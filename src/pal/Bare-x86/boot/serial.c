/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

#include "serial.h"
#include "kernel.h"
#include "idt.h"
#include "io.h"

/* XXX: For debug only */
#include "video.h"

static serial_port_t ports[4] =
{
    {
        .handle = 0,
        .ioaddr = 0x03F8,
        .name = "ttyS0"
    },
    {
        .handle = 0,
        .ioaddr = 0x02F8,
        .name = "ttyS1"
    },
    {
        .handle = 0,
        .ioaddr = 0x03E8,
        .name = "ttyS2"
    },
    {
        .handle = 0,
        .ioaddr = 0x02E8,
        .name = "ttyS3"
    }
};

/*
    IRQ #4 for COM ports 1 or 3
*/
static void serial_irq4_handler(__attribute__((unused)) registers_t *regs)
{
    txt_write_to_screens("4", 0, 78, 0x0E);
}

/*
    IRQ #3 for COM ports 2 or 4
*/
static void serial_irq3_handler(__attribute__((unused)) registers_t *regs)
{
    txt_write_to_screens("3", 0, 78, 0x0E);
}

bool sys_init_serial(serial_id_t port)
{
    uint16_t ioaddr = ports[port].ioaddr;

    hw_cli();

    if ( ioaddr )
    {
        sys_outb(ioaddr + 1, 0x00);    // Disable all interrupts
        sys_outb(ioaddr + 3, 0x80);    // Enable DLAB (set baud rate divisor)
        sys_outb(ioaddr + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
        sys_outb(ioaddr + 1, 0x00);    //                  (hi byte)
        sys_outb(ioaddr + 3, 0x03);    // 8 bits, no parity, one stop bit
        sys_outb(ioaddr + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
        sys_outb(ioaddr + 4, 0x0B);    // IRQs enabled, RTS/DSR set
    }

    switch ( port )
    {
        case SERIAL_COM1:
        case SERIAL_COM3:
            register_interrupt_handler(IRQ4, &serial_irq4_handler);
            break;
        case SERIAL_COM2:
        case SERIAL_COM4:
            register_interrupt_handler(IRQ3, &serial_irq3_handler);
            break;
    }

    hw_sti();

    return true;
}

void sys_terminate_serial(serial_id_t port)
{
    uint16_t ioaddr = ports[port].ioaddr;

    hw_cli();

    if ( ioaddr )
    {
        sys_outb(ioaddr + 1, 0x00);
        sys_outb(ioaddr + 3, 0x00);
        sys_outb(ioaddr + 0, 0x00);
        sys_outb(ioaddr + 1, 0x00);
        sys_outb(ioaddr + 3, 0x00);
        sys_outb(ioaddr + 2, 0x00);
        sys_outb(ioaddr + 4, 0x00);
    }

    switch ( port )
    {
        case SERIAL_COM1:
        case SERIAL_COM3:
            register_interrupt_handler(IRQ4, NULL);
            break;
        case SERIAL_COM2:
        case SERIAL_COM4:
            register_interrupt_handler(IRQ3, NULL);
            break;
    }

    hw_sti();
}

handle_t sys_open_serial(serial_id_t port)
{
    return (handle_t)port;
}

result_t sys_close_serial(__attribute__((unused)) handle_t handle)
{
    return R_OK;
}

uint8_t sys_serial_read_char(handle_t handle)
{
    uint16_t ioaddr = ports[handle].ioaddr;

    while( 0 == (sys_inb(ioaddr + 5) & 0x01) )
    {
        hw_relax();
    }

    uint8_t c = sys_inb(ioaddr);

    return c;
}

char* sys_serial_read_str(__attribute__((unused)) handle_t handle)
{
    return NULL;
}

bool sys_serial_write_char(handle_t handle, uint8_t c)
{
    uint16_t ioaddr = ports[handle].ioaddr;

    while( 0 == (sys_inb(ioaddr + 5) & 0x20) )
    {
        hw_relax();
    }

    sys_outb(ioaddr, c);

    return true;
}

bool sys_serial_write_str(handle_t handle, const char* const str)
{
    const char* pstr = str;

    if ( pstr )
    {
        while (*pstr)
        {
            sys_serial_write_char(handle, *(pstr++));
        }
    }

    return true;
}

void sys_init_serial_ports(void)
{
    if ( !sys_init_serial(SERIAL_COM1) )
    {
        warnk("Warning: sys_init_hw(): Serial port initialization failed.");
    }
}

