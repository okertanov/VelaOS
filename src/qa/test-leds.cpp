/**
    @file       test-leds.cpp
    @brief      QA: HW Leds test

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/

#include "api/VelaOS.h"

/**
    @fn main()
    @brief

    @param[in] argc - argument count
    @param[in] argv - argument vector
    @param[out] none
    @param[in,out] none
    @return EXIT_SUCCESS, EXIT_FAILURE
*/
int main(int argc, char** argv)
{
    UNUSED(argc), UNUSED(argv);

    TRACE0(LOG_DEBUG);

    TRACE(LOG_DEBUG, _T("%s"), _T("1234567"));

    return (EXIT_SUCCESS);
}

