/**
    @file       Debug.h
    @brief      OS Debug interface

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/

#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED


/*******************************************************************************
    Debug
*******************************************************************************/
namespace Vela
{
    namespace Debug
    {

        /**
            @class Vela::Debug::Crash
            @brief Crash class
        */
        class Crash :
            public ABI::Interface,
            public Language::NoCopy,
            public Language::Functor
        {
            public:
                /**
                    @fn Vela::Debug::Crash::Crash()
                */
                Crash();

                /**
                    @fn Vela::Debug::Crash::~Crash()
                */
                virtual ~Crash();
        };

        /**
            @class Vela::Debug::Abort
            @brief Abort class
        */
        class Abort :
            public ABI::Interface,
            public Language::NoCopy,
            public Language::Functor
        {
            public:
                /**
                    @fn Vela::Debug::Abort::Abort()
                */
                Abort();

                /**
                    @fn Vela::Debug::Abort::~Abort()
                */
                virtual ~Abort();
        };

        /**
            @class Vela::Debug::Exit
            @brief Exit class
        */
        class Exit :
            public ABI::Interface,
            public Language::NoCopy,
            public Language::Functor
        {
            public:
                /**
                    @fn Vela::Debug::Exit::Exit()
                */
                Exit();

                /**
                    @fn Vela::Debug::Exit::Exit()
                */
                Exit(int status);

                /**
                    @fn Vela::Debug::Exit::~Exit()
                */
                virtual ~Exit();
        };

        /**
            @class Vela::Debug::Halt
            @brief Halt class
        */
        class Halt :
            public ABI::Interface,
            public Language::NoCopy,
            public Language::Functor
        {
            public:
                /**
                    @fn Vela::Debug::Halt::Halt()
                */
                Halt();

                /**
                    @fn Vela::Debug::Halt::~Halt()
                */
                virtual ~Halt();
        };

        /**
            @class Vela::Debug::Loop
            @brief Loop class
        */
        class Loop :
            public ABI::Interface,
            public Language::NoCopy,
            public Language::Functor
        {
            public:
                enum LoopTimes
                {
                    LOOP_INFINITE   = -1,
                    LOOP_ZERO       = 0,
                    LOOP_ONE        = 1,
                    LOOP_1K         = 1000,
                    LOOP_1M         = 1000000
                };

                /**
                    @fn Vela::Debug::Loop::Loop()
                */
                Loop();

                /**
                    @fn Vela::Debug::Loop::Loop()
                */
                Loop(signed long times);

                /**
                    @fn Vela::Debug::Loop::~Loop()
                */
                virtual ~Loop();

                /**
                    @fn Vela::Debug::Loop::Forever()
                */
                void Forever();

            private:
                /**
                    @fn Vela::Debug::Loop::Run()
                */
                void Run() const;

            private:
                /**
                    @property Vela::Debug::Loop::times_
                */
                signed long times_;
        };

        /**
            @class Vela::Debug::Profiling
            @brief Profiling class
        */
        class Profiling
        {
            public:
                /**
                    @fn Vela::Debug::Profiling::Profiling()
                */
                Profiling();

                /**
                    @fn Vela::Debug::Profiling::Profiling()
                */
                Profiling(const Vela::String& block);

                /**
                    @fn Vela::Debug::Profiling::~Profiling()
                */
                virtual ~Profiling();

                /**
                    @fn Vela::Debug::Profiling::Start()
                */
                void Start();

                /**
                    @fn Vela::Debug::Profiling::Stop()
                */
                void Stop();

                /**
                    @fn Vela::Debug::Profiling::Dump()
                */
                void Dump() const;

            protected:
                /**
                    @fn Vela::Debug::Profiling::Init()
                */
                void Init();

                /**
                    @fn Vela::Debug::Profiling::GetTime()
                */
                unsigned long long GetTime() const;

            private:
                /**
                    @property Vela::Debug::Profiling::tm_start_
                */
                unsigned long long tm_start_;

                /**
                    @property Vela::Debug::Profiling::tm_stop_
                */
                unsigned long long tm_stop_;

                /**
                    @property Vela::Debug::Profiling::ml_freq_
                */
                unsigned long long ml_freq_;

                /**
                    @property Vela::Debug::Profiling::block_name_
                */
                Vela::String block_name_;
        };

        /**
            @class Vela::Debug::ScopedProfiling
            @brief ScopedProfiling class
        */
        class ScopedProfiling :
            public ABI::Interface,
            public Language::NoCopy,
            public Debug::Profiling
        {
            public:
                /**
                    @fn Vela::Debug::ScopedProfiling::ScopedProfiling()
                */
                ScopedProfiling();

                /**
                    @fn Vela::Debug::ScopedProfiling::ScopedProfiling()
                */
                ScopedProfiling(const Vela::String& block);

                /**
                    @fn Vela::Debug::ScopedProfiling::~ScopedProfiling()
                */
                virtual ~ScopedProfiling();
        };

        /**
            @class Vela::Debug::WrapProfiling
            @brief WrapProfiling class
        */
        class WrapProfiling :
            public ABI::Interface,
            public Language::NoCopy,
            public Debug::Profiling
        {
            public:
                /**
                    @fn Vela::Debug::WrapProfiling::WrapProfiling()
                */
                WrapProfiling();

                /**
                    @fn Vela::Debug::WrapProfiling::WrapProfiling()
                */
                WrapProfiling(const Vela::String& block);

                /**
                    @fn Vela::Debug::WrapProfiling::~WrapProfiling()
                */
                virtual ~WrapProfiling();
        };

        /*
            Dump()
            Stack()
            Trace()
            Memory()
            Assert()
        */

    }
}

/**
    @def SCOPE_PROFILING
    @brief
*/
#if defined(TARGET_WIN32) || defined(TARGET_POSIX)
#define SCOPE_PROFILING(S)    Vela::Debug::ScopedProfiling tmp_scoped_profiling(S)
#else
#define SCOPE_PROFILING(S)    VOID_FUNCTION
#endif

/**
    @def SCOPE_PROFILING0
    @brief
*/
#if defined(TARGET_WIN32) || defined(TARGET_POSIX)
#define SCOPE_PROFILING0()    Vela::Debug::ScopedProfiling tmp_scoped_profiling(\
                                        (Vela::String(__PRETTY_FUNCTION__) + TEXT(":") + \
                                         Vela::String(__LINE__)) )
#else
#define SCOPE_PROFILING0()    VOID_FUNCTION
#endif

/**
    @def WRAP_PROFILING
    @brief
*/
#define WRAP_PROFILING(S)

/**
    @def WRAP_PROFILING
    @brief
*/
#define WRAP_PROFILINGO()

#endif /*DEBUG_H_INCLUDED*/

