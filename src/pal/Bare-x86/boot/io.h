/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

#pragma once

#include "types.h"

uint8_t sys_inb(uint16_t port);
void sys_outb(uint16_t port, uint8_t value);
uint16_t sys_inw(uint16_t port);
void sys_outw(uint16_t port, uint16_t value);

