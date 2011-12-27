/**
    @file       test-log.cpp
    @brief      QA: Logging test

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

    SCOPE_PROFILING0();

    return (EXIT_SUCCESS);
}

