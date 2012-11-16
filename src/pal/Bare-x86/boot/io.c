/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

#include "io.h"

uint8_t sys_inb(uint16_t port)
{
    uint8_t ret;
    __asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

void sys_outb(uint16_t port, uint8_t value)
{
    __asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

uint16_t sys_inw(uint16_t port)
{
    uint16_t ret;
    __asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

void sys_outw(uint16_t port, uint16_t value)
{
    __asm volatile ("outw %1, %0" : : "dN" (port), "a" (value));
}

