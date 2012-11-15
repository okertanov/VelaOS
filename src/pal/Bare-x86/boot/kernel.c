/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

#define MULTIBOOT_LOADER_MAGIC  0x2BADB002
#define VIDEORAM_BASE           0x000B8000

static volatile unsigned short* const videoram = (unsigned short*)VIDEORAM_BASE;

void txt_write_to_screens(const char* const str, unsigned short row, unsigned short col, unsigned char mask)
{
    volatile unsigned short* pvideo = videoram + (row * 80 + col);
    unsigned int idx = 0;

    while( str[idx] != 0 )
    {
        *pvideo++ = (unsigned short)(str[idx++] | (mask << 8));
    }
}

void txt_clear_screen(void)
{
    volatile unsigned short* pvideo = videoram;
    unsigned int sz = 0;

    while( sz++ < 80 * 25 )
    {
        *pvideo++ = (unsigned short)(32 | (0x08 << 8));
    }
}

int kmain(unsigned int magic, void* mb_info)
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
            (char*)(((long*)mb_info)[16]) :
            "Unknown bootloader.";

        /* Resources setup: GDT, IDT */
        /* ... */

        /* Then enable interrupts */
        /*asm volatile ("sti");*/

        /* Display bootloader's name */
        txt_write_to_screens(boot_loader_name, 0, 0, 0x07);

        /* Display status */
        txt_write_to_screens("Zeno: Load complete.", 1, 0, 0x02);

        /* OS Loop */
        unsigned long long counter = 0;
        char* dashes[] = {"|","/","-","\\"};
        while( 1 )
        {
            /* Show progress */
            txt_write_to_screens(dashes[counter++ % 4], 2, 0, 0x0A);
            /*asm volatile ("hlt");*/
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

