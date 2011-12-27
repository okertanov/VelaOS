/**
    @file       Platform.cpp
    @brief      Platform implementation

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/

#include "Platform.h"

/*******************************************************************************
    Platform
*******************************************************************************/
namespace Vela
{
    namespace Platform
    {

        /**
            @var Vela::Platform::System::osname_
            @brief
        */
        String System::osname_ = VELA_NAME;

        /**
            @var Vela::Platform::System::versionid_
            @brief
        */
        VersionId System::versionid_ = VELA_VERSION;

        /**
            @var Vela::Platform::System::platformid_
            @brief
        */
        PlatformId System::platformid_ = VELA_PLATFORM;

        /**
            @fn Vela::Platform::System::GetOSName
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        const String& System::GetOSName()
        {
            return osname_;
        }

        /**
            @fn Vela::Platform::System::GetOSVersionId
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        VersionId System::GetOSVersionId()
        {
            return versionid_;
        }

        /**
            @fn Vela::Platform::System::GetOSVersionStr
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        const String& System::GetOSVersionStr()
        {
            static String version(GetOSVersionId());

            return version;
        }

        /**
            @fn Vela::Platform::System::GetPlatformId
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        PlatformId System::GetPlatformId()
        {
            return platformid_;
        }

        /**
            @fn Vela::Platform::System::GetPlatformStr
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        const String& System::GetPlatformStr()
        {
            static String platform(GetPlatformId());

            return platform;
        }

        /**
            @fn Vela::Platform::System::GetUptime
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        time_t System::GetUptime()
        {
            return 0;
        }

    }
}

