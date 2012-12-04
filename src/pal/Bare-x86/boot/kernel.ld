/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

/*OUTPUT_FORMAT("elf32-i386")*/

ENTRY (start)

SECTIONS
{
    . = 0x00100000;

    __image_start__ = . ;

    .text ALIGN (0x1000) :
    {
        __text_start__ = . ;
        *(.text)
        __text_end__ = . ;
    }

    __xen_guest ALIGN (0x1000) :
    {
        __xen_guest_start__ = . ;
        *(__xen_guest)
        __xen_guest_end__ = . ;
    }

    . = 0x00104000;

    .xen_shared_info ALIGN (0x4000) :
    {
        __xen_shared_info_start__ = . ;
        *(.xen_shared_info)
        . += 0x4000;
        __xen_shared_info_end__ = . ;
    }

    . = 0x00108000;

    .xen_hypercall_page ALIGN (0x4000) :
    {
        __xen_hypercall_page_start__ = . ;
        *(.xen_hypercall_page)
        . += 0x4000;
        __xen_hypercall_page_end__ = . ;
    }

    .rodata ALIGN (0x1000) :
    {
        __rodata_start__ = . ;
        *(.rodata)
        *(.rdata)
         __rodata_end__ = . ;
    }

    .data ALIGN (0x1000) :
    {
        __data_start__ = . ;
        *(.data)
        __data_end__ = . ;
    }

    .note ALIGN (0x1000) :
    {
        __note_start__ = . ;
        *(.note.*)
        __note_end__ = . ;
    }

    .bss ALIGN (0x1000) :
    {
        __bss_start__ = . ;
        *(COMMON)
        *(.bss)
        __bss_end__ = . ;
    }

    .end ALIGN (0x1000) :
    {
        __image_end__ = . ;
    }
}

