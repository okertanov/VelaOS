/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

#include "video.h"
#include "io.h"

volatile uint16_t* const videoram = (uint16_t*)VIDEORAM_BASE;

static volatile uint16_t txt_pos_row = 0;
static volatile uint16_t txt_pos_col = 0;

void txt_write_to_screens(const char* const str, uint16_t row, uint16_t col, uint8_t mask)
{
    volatile uint16_t* pvideo = videoram + (row * 80 + col);
    unsigned int idx = 0;

    while( str[idx] != 0 )
    {
        *pvideo++ = (uint16_t)(str[idx++] | (mask << 8));
    }
}

void txt_clear_screen(void)
{
    volatile uint16_t* pvideo = videoram;
    unsigned int sz = 0;

    while( sz++ < 80 * 25 )
    {
        *pvideo++ = (uint16_t)(32 | (0x08 << 8));
    }

    txt_pos_row = 0;
    txt_pos_col = 0;
}

void txt_move_cursor(uint16_t row, uint16_t col)
{
   uint16_t loc = row * 80 + col;
   sys_outb(0x3D4, 14);
   sys_outb(0x3D5, loc >> 8);
   sys_outb(0x3D4, 15);
   sys_outb(0x3D5, loc);

   txt_pos_row = row;
   txt_pos_col = col;
}

