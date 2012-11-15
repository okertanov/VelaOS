/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

OUTPUT_FORMAT("pe-i386")

ENTRY (start)

SECTIONS
{
    . = 0x00100000;

    .text ALIGN (0x1000) :
    {
        *(.text)
        __text_end__ = . ;
    }

    .rodata ALIGN (0x1000) :
    {
        *(.rodata*)
        __rodata_end__ = . ;
    }

    .data ALIGN (0x1000) :
    {
        *(.data)
        *(.data2)
        *(.rdata)
        __data_end__ = . ;
    }

    .bss ALIGN (0x1000) :
    {
        __bss_start__ = . ;
        *(COMMON)
        *(.bss)
        __bss_end__ = . ;
    }
}

