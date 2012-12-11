/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

#pragma once

#include "types.h"

#define MULTIBOOT_LOADER_MAGIC  0x2BADB002

#define KERNEL_NAME             "Zeno"
#define KERNEL_VERSION          ((0x01 << 16) | (0x03))

extern char* kernel_name;
extern uint32_t kernel_version;


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
#define hw_relax()  __asm volatile("rep; nop")

int sys_main(unsigned int magic, void* mb_info, void* xen_start_info);

extern void terminate(void);

void panick(const char* what);
void warnk(const char* what);

