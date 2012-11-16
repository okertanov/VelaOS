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
#include "timer.h"

int sys_main(unsigned int magic, void* mb_info)
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
        char* boot_loader_name = mb_flags | (1 << 9) ?
            (char*)(((unsigned long*)mb_info)[16]) :
            "Unknown bootloader.";

        /* HW discovery */
        /* ... */

        /* Resources init: GDT, IDT */
        sys_init_gtd();
        sys_init_idt();
        sys_init_mem();
        sys_init_timer();
        sys_init_hw();

        /* Then enable interrupts */
        hw_sti();

        /* Display bootloader's name */
        txt_write_to_screens(boot_loader_name, 0, 0, 0x07);

        /* Display status */
        txt_write_to_screens("Zeno: Load complete.", 1, 0, 0x02);

        /* OS Loop */
        uint64_t counter = 0;
        static char* dashes[] = {"|","/","-","\\"};
        while( true )
        {
            /* Show progress */
            txt_write_to_screens(dashes[counter++ % 4], 2, 0, 0x0A);
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

void sys_init_mem(void)
{
}

void sys_init_hw(void)
{
}

