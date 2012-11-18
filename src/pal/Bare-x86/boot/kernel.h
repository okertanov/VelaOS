/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

#pragma once

#include "types.h"

#define MULTIBOOT_LOADER_MAGIC  0x2BADB002

extern const uint32_t __image_start__, __image_end__;
extern const uint32_t __text_start__, __text_end__;
extern const uint32_t __rodata_start__, __rodata_end__;
extern const uint32_t __data_start__, __data_end__;
extern const uint32_t __bss_start__, __bss_end__;

#define ld_image_start  ((uint32_t)&__image_start__)
#define ld_image_end    ((uint32_t)&__image_end__)

#define hw_cli()    __asm volatile("cli")
#define hw_sti()    __asm volatile("sti")
#define hw_halt()   __asm volatile("hlt")
#define hw_reboot() __asm volatile("cli; mov $0, %eax; lidt (%eax); sti; int $0")

int sys_main(unsigned int magic, void* mb_info);

