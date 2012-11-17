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

char *itoa(int num, char *str, int radix)
{
    char sign = 0;

    //an int can only be 16 bits long
    char temp[17] = {0};

    //at radix 2 (binary) the string
    //is at most 16 + 1 null long.
    int temp_loc = 0;
    int digit;
    int str_loc = 0;

    //save sign for radix 10 conversion
    if (radix == 10 && num < 0)
    {
        sign = 1;
        num = -num;
    }

    //construct a backward string of the number.
    do
    {
        digit = (unsigned int)num % radix;
        if (digit < 10)
        {
            temp[temp_loc++] = digit + '0';
        }
        else
        {
            temp[temp_loc++] = digit - 10 + 'A';
        }
        num = (unsigned int)num / radix;
    }
    while ((unsigned int)num > 0);

    //now add the sign for radix 10
    if (radix == 10 && sign)
    {
        temp[temp_loc] = '-';
    }
    else
    {
        temp_loc--;
    }

    //now reverse the string.
    while ( temp_loc >= 0 )
    { // while there are still chars
        str[str_loc++] = temp[temp_loc--];
    }

    // add null termination.
    str[str_loc] = 0;

    return str;
}

