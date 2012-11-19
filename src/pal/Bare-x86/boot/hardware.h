/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

#pragma once

#include "types.h"

void sys_init_hw(void);

typedef enum serial_port_enum
{
    SERIAL_COM1 = 0x03F8,
    SERIAL_COM2 = 0x02F8,
    SERIAL_COM3 = 0x03E8,
    SERIAL_COM4 = 0x02E8,
} serial_port_t;

handle_t sys_init_serial(serial_port_t port);
void sys_terminate_serial(handle_t handle);
uint8_t sys_serial_read_char(handle_t handle);
bool sys_serial_write_char(handle_t handle, uint8_t c);
bool sys_serial_write_str(handle_t handle, const char* const str);

