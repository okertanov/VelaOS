/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

#define MULTIBOOT_HEADER_MAGIC  0x1BADB002
#define VIDEORAM_BASE           0xB8000

static volatile unsigned short * const videoram = (unsigned short*)VIDEORAM_BASE;

int kmain(unsigned int magic, void* mb_info)
{
   if ( magic == MULTIBOOT_HEADER_MAGIC )
   {
       /* Multiboot data */
       char* boot_loader_name =(char*)(((long*)mb_info)[16]);

       /* Resources setup */
       /* ... */

       /* Enable interrupts */
       asm volatile ("sti");

       /* Access Video RAM */
       videoram[0] = boot_loader_name[0] | 0x0700;
       videoram[1] = boot_loader_name[1] | 0x0700;
       videoram[2] = boot_loader_name[2] | 0x0700;
       videoram[3] = boot_loader_name[3] | 0x0700;
   }
   else
   {
       /* khalt() */
   }

   return MULTIBOOT_HEADER_MAGIC;
}

