/**
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
*/

#include "util.h"

void* memset(void *block, int c, size_t len)
{
    char *bblock;

    for (bblock = (char *)block; len--; )
    {
        *bblock++ = c;
    }

    return (block);
}
