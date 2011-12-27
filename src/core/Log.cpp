/**
    @file       Log.cpp
    @brief      Logging implementation

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/

#include "Platform.h"
#include "Log.h"

/*******************************************************************************
 Log
*******************************************************************************/
namespace Vela
{
    namespace Log
    {

        /**
            @var Vela::Log::LoggerInstance
        */
        Logger LoggerInstance;

        /**
            @fn Vela::Log::Logger::Logger
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Logger::Logger()
            : level_(Logger::LL_WARNING),
                stream_()
        {
        }

        /**
            @fn Vela::Log::Logger::Logger
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Logger::Logger(LogLevel lvl)
            : level_(lvl),
                stream_()
        {
        }

        /**
            @fn Vela::Log::Logger::~Logger
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
        Logger::~Logger()
        {
        }
        #else
        #warning "Not implemented for this toolchain."
        #endif

        /**
            @fn Vela::Log::Logger::Self()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Logger const& Logger::Self() const
        {
            return *this;
        }

        /**
            @fn Vela::Log::Logger::Level()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Logger::LogLevel Logger::Level() const
        {
            return level_;
        }

        /**
            @fn Vela::Log::Logger::Stream
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        LogStream const& Logger::Stream() const
        {
            return stream_;
        }

        /**
            @fn Vela::Log::Logger::Write
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        void Logger::Write(LogLevel lvl, const String& fmt, ...) const
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            va_list args;
            va_start(args, fmt);
            Publish(lvl, fmt, args);
            va_end(args);
            #else
            #warning "Not implemented for this toolchain."
            #endif
        }

        /**
            @fn Vela::Log::Logger::Trace
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        void Logger::Trace(LogLevel lvl, const String& fmtt, const String& fmtu, ...) const
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            const String fmt = fmtt + fmtu;

            va_list args;
            va_start(args, fmtu);
            Publish(lvl, fmt, args) << LOG_ENDL;
            va_end(args);
            #else
            #warning "Not implemented for this toolchain."
            #endif
        }

        /**
            @enum Vela::Log::TEMP_BUFFER_SIZE
            @brief
        */
        enum { TEMP_BUFFER_SIZE = 1024 };

        /**
            @fn Vela::Log::Logger::Publish
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
        Logger& Logger::Publish(LogLevel lvl, const String& fmt, const va_list ap) const
        {
            UNUSED(lvl);

            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            static char buffer[TEMP_BUFFER_SIZE] = {0};

            int size = vsnprintf(buffer, TEMP_BUFFER_SIZE, fmt, ap);

            if ( size )
            {
                std::cerr << buffer;
            }
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(fmt), UNUSED(ap);
            #endif

            return const_cast<Logger&>(Self());
        }
        #else
        #warning "Not implemented for this toolchain."
        #endif

    }
}

