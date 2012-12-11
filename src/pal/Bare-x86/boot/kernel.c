/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

#include "kernel.h"
#include "util.h"
#include "video.h"
#include "io.h"
#include "gdt.h"
#include "idt.h"
#include "memory.h"
#include "event.h"
#include "timer.h"
#include "serial.h"
#include "paravirt.h"
#include "sched.h"

char* kernel_name = KERNEL_NAME;
uint32_t kernel_version = KERNEL_VERSION;

int sys_main( unsigned int magic,
              __attribute__((unused)) void* mb_info,
              __attribute__((unused)) void* xen_start_info )
{
    /* Clear screen */
    txt_clear_screen();

    /* If it running under the multiboot environment */
    if ( magic == MULTIBOOT_LOADER_MAGIC )
    {
        /* Parse multiboot data */
        unsigned long mb_flags = (unsigned long)(((unsigned long*)mb_info)[0]);
        __attribute__((unused)) unsigned long mb_mem_lower = mb_flags | 1 ?
            (unsigned long)(((unsigned long*)mb_info)[1]) :
            0x000A0000; /* 640Kb */
        __attribute__((unused)) unsigned long mb_mem_upper = mb_flags | 1 ?
            (unsigned long)(((unsigned long*)mb_info)[2]) :
            0x00100000; /* 1Mb */
        __attribute__((unused)) unsigned long mb_boot_device = mb_flags | (1 << 1) ?
            (unsigned long)(((unsigned long*)mb_info)[3]) :
            0x00;
        __attribute__((unused)) char* mb_loader_name = mb_flags | (1 << 9) ?
            (char*)(((unsigned long*)mb_info)[16]) :
            "Unknown bootloader.";

        /* Resources initialization */
        sys_init_gtd();
        sys_init_idt();
        sys_init_timer();
        sys_init_memory();

        /* Then enable interrupts */
        hw_sti();

        /* Continue initialization */
        sys_init_serial_ports();
        sys_init_sched();

        /* Setup output devices: text-mode video, serial line */
        handle_t hserial = sys_open_serial(SERIAL_COM1);

        /* Display bootloader's name */
        txt_write_to_screens(mb_loader_name, 0, 0, 0x02);
        sys_serial_write_str(hserial, mb_loader_name);
        sys_serial_write_str(hserial, "\n");

        /* Display status */
        static char* load_complete_str = "Zeno: Load complete.";
        txt_write_to_screens(load_complete_str, 1, 0, 0x02);
        sys_serial_write_str(hserial, load_complete_str);
        sys_serial_write_str(hserial, "\n");

        /* Display memory */
        char buff[32] = {0};
        txt_write_to_screens("Memory Lower:", 2, 0, 0x07);
        txt_write_to_screens(itoa(mb_mem_lower, buff, 10), 2, 14, 0x07);
        txt_write_to_screens("Memory Upper:", 3, 0, 0x07);
        txt_write_to_screens(itoa(mb_mem_upper, buff, 10), 3, 14, 0x07);

        /* Display boot device */
        txt_write_to_screens("Boot device:", 4, 0, 0x07);
        txt_write_to_screens("0x", 4, 13, 0x07);
        txt_write_to_screens(itoa(mb_boot_device, buff, 16), 4, 15, 0x07);

        /* Display simple menu */
        static char* simple_menu_str = "(s) shell, (t) trap, (r) reboot, (h) halt";
        txt_write_to_screens(simple_menu_str, 24, 0, 0x07);
        sys_serial_write_str(hserial, simple_menu_str);
        sys_serial_write_str(hserial, "\n");

        /* OS Loop */
        uint64_t counter = 0;
        static char* dashes[] = {"\x7C", "\x2F", "\x2D", "\x5C"};
        while( true )
        {
            /* Show progress */
            txt_write_to_screens(dashes[counter++ % 4], 1, 21, 0x0A);

            /* Read early serial */
            uint8_t ch = sys_serial_read_char(hserial);

            /* Then echo it back */
            /* XXX: For debug only */
            if ( ch )
                sys_serial_write_char(hserial, ch);

            switch ( ch )
            {
                case 's':
                    sys_serial_write_str(hserial, "shell$ ");
                    break;
                case 't':
                    terminate();
                    break;
                case 'r':
                    hw_reboot();
                    break;
                case 'h':
                    panick("System halted.");
                    break;
            }

            /* Idle */
            hw_halt();
        }
    }
    else
    {
        /* Display error */
        txt_write_to_screens("BAD MAGIC", 0, 0, 0x0E);
        /* Display status */
        txt_write_to_screens("Zeno: Load failed.", 1, 0, 0x0C);
    }

    return MULTIBOOT_LOADER_MAGIC;
}

void panick(const char* what)
{
    txt_write_to_screens(what, 23, 0, 0x0C);
    terminate();
}

void warnk(const char* what)
{
    txt_write_to_screens(what, 23, 0, 0x0E);
}

