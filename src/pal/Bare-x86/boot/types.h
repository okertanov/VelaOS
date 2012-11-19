/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

#pragma once

/*
    Std Types
*/
typedef signed char         int8_t;
typedef unsigned char       uint8_t;
typedef short               int16_t;
typedef unsigned short      uint16_t;
typedef int                 int32_t;
typedef unsigned int        uint32_t;
typedef long long           int64_t;
typedef unsigned long long  uint64_t;

typedef int                 intptr_t;
typedef unsigned            int uintptr_t;

typedef long int            ptrdiff_t;

typedef unsigned long       size_t;

typedef _Bool               bool;
#define bool                bool
#define false               0
#define true                1

#ifndef NULL
#define NULL    ((void *)0)
#endif

/*
    System types
*/
typedef uint32_t            handle_t;

