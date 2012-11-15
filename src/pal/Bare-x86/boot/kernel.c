/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

#define MULTIBOOT_HEADER_MAGIC  0x1BADB002
#define VIDEORAM_BASE           0x000B8000

static volatile unsigned short* const videoram = (unsigned short*)VIDEORAM_BASE;

void txt_write_to_screens(const char* const str, unsigned char mask)
{
    volatile unsigned short* pvideo = videoram;
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
    /* Enable interrupts */
    asm volatile ("sti");

    txt_clear_screen();

    if ( magic == MULTIBOOT_HEADER_MAGIC )
    {
        /* Multiboot data */
        char* boot_loader_name =(char*)(((long*)mb_info)[16]);

        /* Resources setup */
        /* ... */

        /* Access Video RAM */
        txt_write_to_screens(boot_loader_name, 0x07);
    }
    else
    {
        txt_write_to_screens("BAD MAGIC", 0x0E);
    }

    return MULTIBOOT_HEADER_MAGIC;
}

