/**
    @file       Platform.h
    @brief      Platform header

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/

#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED

/*******************************************************************************
    Platform Definition Includes
*******************************************************************************/
#include "PlatformDefs.h"

/*******************************************************************************
    System Includes
*******************************************************************************/
#if defined(TARGET_WIN32) || defined(TARGET_POSIX)
#include <cstdlib>
#include <cstdarg>
#include <cstdio>
#include <cstring>

#include <string>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <functional>

#include <sys/time.h>
#endif

#if defined(TARGET_EMBEDDED)
#endif

#if defined(TARGET_STM32)
#endif

/*******************************************************************************
    Project Includes
*******************************************************************************/
#include "ABI.h"
#include "Types.h"
#include "Language.h"

#if defined(TARGET_WIN32)
#include "pal/Win32/Win32Platform.h"
#elif defined(TARGET_POSIX)
#include "pal/Posix/PosixPlatform.h"
#elif defined(TARGET_STM32)
#include "pal/STM32/STM32Platform.h"
#endif

/*******************************************************************************
    Platform
*******************************************************************************/
namespace Vela
{
    namespace Platform
    {

        /**
            @enum Vela::Platform::VersionId
            @brief
        */
        enum VersionId
        {
            V_01_00 = 0x00000100 /*Oct. 2011*/
        };

        /**
            @enum Vela::Platform::PlatformId
            @brief
        */
        enum PlatformId
        {
            VELA_PLATFORM_UNKNOWN = 0,
            VELA_PLATFORM_STM32   = 16,
            VELA_PLATFORM_WIN32   = 32,
            VELA_PLATFORM_WIN64   = 64,
            VELA_PLATFORM_POSIX   = 128
        };

        /**
            @class Vela::Platform::System
            @brief System class
        */
        class System :
            public ABI::Singleton<System>,
            public Language::NoCopy,
            public Language::NoInstance
        {
            public:
                /**
                    @fn Vela::Platform::System::GetOSName()
                */
                static const String& GetOSName();

                /**
                    @fn Vela::Platform::System::GetOSVersionStr()
                */
                static const String& GetOSVersionStr();

                /**
                    @fn Vela::Platform::System::GetOSVersionId()
                */
                static VersionId GetOSVersionId();

                /**
                    @fn Vela::Platform::System::GetPlatformStr()
                */
                static const String& GetPlatformStr();

                /**
                    @fn Vela::Platform::System::GetPlatformId()
                */
                static PlatformId GetPlatformId();

                /**
                    @fn Vela::Platform::System::GetUptime()
                */
                static time_t GetUptime();

            private:
                /**
                    @property Vela::Platform::System::osname_
                */
                static String       osname_;

                /**
                    @property Vela::Platform::System::versionid_
                */
                static VersionId    versionid_;

                /**
                    @property Vela::Platform::System::platformid_
                */
                static PlatformId   platformid_;
        };

    }
}

#endif /*PLATFORM_H_INCLUDED*/

