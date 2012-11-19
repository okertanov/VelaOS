/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

#include "hardware.h"
#include "kernel.h"
#include "idt.h"
#include "io.h"

void sys_init_hw(void)
{
    __attribute__((unused)) handle_t serial = sys_init_serial(SERIAL_COM1);
    if ( serial )
    {
        sys_serial_write_str(serial, kernel_name);
    }
    else
    {
        warnk("Warning: sys_init_hw(): " "Invalid serial port handle.");
    }
}

/*
    IRQ #4 for COM ports 1 or 3
*/
static void serial_irq4_handler(__attribute__((unused)) registers_t *regs)
{
}

/*
    IRQ #3 for COM ports 2 or 4
*/
static void serial_irq3_handler(__attribute__((unused)) registers_t *regs)
{
}

handle_t sys_init_serial(serial_port_t port)
{
    handle_t handle = 0;
    uint16_t ioaddr = port;

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

        handle = (handle_t)ioaddr;
    }

    register_interrupt_handler(IRQ3, &serial_irq3_handler);
    register_interrupt_handler(IRQ4, &serial_irq4_handler);

    hw_sti();

    return handle;
}

void sys_terminate_serial(handle_t handle)
{
    uint16_t ioaddr = (uint16_t)(handle);

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
}

uint8_t sys_serial_read_char(handle_t handle)
{
    uint16_t ioaddr = (uint16_t)(handle);

    while( 0 == (sys_inb(ioaddr + 5) & 0x01) )
    {
        hw_relax();
    }

    uint8_t c = sys_inb(ioaddr);

    return c;
}

bool sys_serial_write_char(handle_t handle, uint8_t c)
{
    uint16_t ioaddr = (uint16_t)(handle);

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

