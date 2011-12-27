/**
    @file       test-init.cpp
    @brief      QA: System initialization test

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

    TRACE(  LOG_INFO,
            TEXT("test-init OS Name: %s/%s on %s"),
            static_cast<const char*>(Vela::Platform::System::GetOSName()),
            static_cast<const char*>(Vela::Platform::System::GetOSVersionStr()),
            static_cast<const char*>(Vela::Platform::System::GetPlatformStr()) );

    #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
    LOG_INSTANCE << TEXT("test-init terminating with code: ")
                 << EXIT_SUCCESS << std::hex << EXIT_SUCCESS << std::endl;
    LOG_INSTANCE << Vela::String("Done.") << std::endl;
    #endif

    return (EXIT_SUCCESS);
}

