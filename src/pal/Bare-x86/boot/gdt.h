/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

#pragma once

#include "types.h"

typedef struct gdt_entry_struct
{
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t  base_middle;
    uint8_t  access;
    uint8_t  granularity;
    uint8_t  base_high;
} __attribute__((packed)) gdt_entry_t;

typedef struct gdt_ptr_struct
{
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) gdt_ptr_t;

void sys_init_gtd(void);
extern void gdt_flush(uint32_t);
void gdt_set_gate(int32_t, uint32_t, uint32_t, uint8_t, uint8_t);

