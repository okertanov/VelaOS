/**
    @file       Debug.cpp
    @brief      OS Debug interface implementation

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/

#include "Platform.h"
#include "Debug.h"
#include "Log.h"

/*******************************************************************************
    Debug
*******************************************************************************/
namespace Vela
{
    namespace Debug
    {

        /**
            @fn Vela::Debug::Crash::Crash()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Crash::Crash()
        {
            *((unsigned int*)0) = 0xC4A581;
        }

        /**
            @fn Vela::Debug::Crash::~Crash()
            @brief
            @warning Normally it isn't reachable

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Crash::~Crash()
        {
        }

        /**
            @fn Vela::Debug::Abort::Abort()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Abort::Abort()
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            __builtin_abort();
            #else
            #warning "Not implemented for this toolchain."
            #endif
        }

        /**
            @fn Vela::Debug::Abort::~Abort()
            @brief
            @warning Normally it isn't reachable

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Abort::~Abort()
        {
        }

        /**
            @fn Vela::Debug::Exit::Exit()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Exit::Exit()
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            __builtin_exit(EXIT_SUCCESS);
            #else
            #warning "Not implemented for this toolchain."
            #endif
        }

        /**
            @fn Vela::Debug::Exit::Exit()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Exit::Exit(int status)
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            __builtin_exit(status);
            #else
            #warning "Not implemented for this toolchain."
            #endif
        }

        /**
            @fn Vela::Debug::Exit::~Exit()
            @brief
            @warning Normally it isn't reachable

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Exit::~Exit()
        {
        }

        /**
            @fn Vela::Debug::Halt::Halt()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Halt::Halt()
        {
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            __asm__ __volatile__ ("hlt");
            #else
            #warning "Not implemented for this toolchain."
            #endif
        }

        /**
            @fn Vela::Debug::Halt::~Halt()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Halt::~Halt()
        {
        }

        /**
            @fn Vela::Debug::Loop::Loop()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Loop::Loop()
            : times_(LOOP_ZERO)
        {
            Run();
        }

        /**
            @fn Vela::Debug::Loop::Loop()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Loop::Loop(signed long times)
            : times_(times)
        {
            Run();
        }

        /**
            @fn Vela::Debug::Loop::~Loop()
            @brief
            @warning May be not reachable

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Loop::~Loop()
        {
        }

        /**
            @fn Vela::Debug::Loop::Forever()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        void Loop::Forever()
        {
            times_ = LOOP_INFINITE;
            Run();
        }

        /**
            @fn Vela::Debug::Loop::Run()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        void Loop::Run() const
        {
            volatile signed long times = times_;

            if (LOOP_INFINITE == times)
                while (true) __asm__ __volatile__ ("nop");
            else
                while (times-- > 0) __asm__ __volatile__ ("nop");
        }

        /**
            @fn Vela::Debug::Profiling::Profiling()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Profiling::Profiling()
            : tm_start_(0), tm_stop_(0), ml_freq_(0),
                block_name_(TEXT("<unnamed block>"))
        {
            Init();
        }

        /**
            @fn Vela::Debug::Profiling::Profiling()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Profiling::Profiling(const Vela::String& name)
            : tm_start_(0), tm_stop_(0), ml_freq_(0),
                block_name_(name)
        {
            Init();
        }

        /**
            @fn Vela::Debug::Profiling::~Profiling()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        Profiling::~Profiling()
        {
        }

        /**
            @fn Vela::Debug::Profiling::Start()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        void Profiling::Start()
        {
            tm_start_ = GetTime();
        }

        /**
            @fn Vela::Debug::Profiling::Stop()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        void Profiling::Stop()
        {
            tm_stop_ = GetTime();
        }

        /**
            @fn Vela::Debug::Profiling::Init()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        void Profiling::Init()
        {
            tm_start_ = tm_stop_ = 0;
            ml_freq_ = 1;
        }

        /**
            @fn Vela::Debug::Profiling::GetTime()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        unsigned long long Profiling::GetTime() const
        {
            unsigned long long time = 0;

            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            ::timeval tv;
            ::gettimeofday(&tv, NULL);
            time = ((tv.tv_sec * 1000000) + tv.tv_usec) / ml_freq_;
            #else
            #warning "Not implemented for this toolchain."
            #endif

            return time;
        }

        /**
            @fn Vela::Debug::Profiling::Dump()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        void Profiling::Dump() const
        {
            const double OneMillisecond = 1000.;
            const double OneSecond = 1000000.;

            unsigned long long tm_uc_diff = (tm_stop_ - tm_start_);
            bool is_in_seconds = (tm_uc_diff >= OneSecond);
            double tm_human_diff = tm_uc_diff /
                (is_in_seconds ? OneSecond : OneMillisecond);

            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            LOG_INSTANCE << _T("Profiling for [") << block_name_ << _T("] ")
                         << std::dec << tm_uc_diff << _T("us")
                         << _T("(") << tm_human_diff << (is_in_seconds ? _T("s") : _T("ms")) << _T(").")
                         << std::endl;
            #else
            #warning "Not implemented for this toolchain."
            UNUSED(tm_human_diff);
            #endif
        }

        /**
            @fn Vela::Debug::ScopedProfiling::ScopedProfiling()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        ScopedProfiling::ScopedProfiling()
            : Profiling()
        {
            Start();
        }

        /**
            @fn Vela::Debug::ScopedProfiling::ScopedProfiling()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        ScopedProfiling::ScopedProfiling(const Vela::String& name)
            : Profiling(name)
        {
            Start();
        }

        /**
            @fn Vela::Debug::ScopedProfiling::~ScopedProfiling()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        ScopedProfiling::~ScopedProfiling()
        {
            Stop();
            Dump();
        }

        /**
            @fn Vela::Debug::WrapProfiling::WrapProfiling()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        WrapProfiling::WrapProfiling()
            : Profiling()
        {
        }

        /**
            @fn Vela::Debug::WrapProfiling::WrapProfiling()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        WrapProfiling::WrapProfiling(const Vela::String& name)
            : Profiling(name)
        {
        }

        /**
            @fn Vela::Debug::WrapProfiling::~WrapProfiling()
            @brief

            @param[in]
            @param[out]
            @param[in,out]
            @return
        */
        WrapProfiling::~WrapProfiling()
        {
        }

    }
}

