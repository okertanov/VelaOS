/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

#pragma once

#include "types.h"

void sys_init_serial_ports(void);

typedef enum serial_id_enum
{
    SERIAL_COM1 = 0,
    SERIAL_COM2 = 1,
    SERIAL_COM3 = 2,
    SERIAL_COM4 = 3
} serial_id_t;

typedef struct serial_port_struct
{
    handle_t handle;
    uint16_t ioaddr;
    char name[];
} serial_port_t;

bool sys_init_serial(serial_id_t port);
void sys_terminate_serial(serial_id_t port);

handle_t sys_open_serial(serial_id_t port);
result_t sys_close_serial(handle_t handle);

uint8_t sys_serial_read_char(handle_t handle);
char* sys_serial_read_str(handle_t handle);
bool sys_serial_write_char(handle_t handle, uint8_t c);
bool sys_serial_write_str(handle_t handle, const char* const str);

