/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

#pragma once

#include "types.h"

#define VIDEORAM_BASE           0x000B8000

void txt_write_to_screens(const char* const str, uint16_t row, uint16_t col, uint8_t mask);
void txt_clear_screen(void);
void txt_move_cursor(uint16_t row, uint16_t col);

