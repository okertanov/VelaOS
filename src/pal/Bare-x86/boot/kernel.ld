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
        *(.rodata*)
        *(.rdata*)
        __text_end__ = . ;
    }

    .data ALIGN (0x1000) :
    {
        __data_start__ = . ;
        *(.data*)
        __data_end__ = . ;
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

