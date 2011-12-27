/**
    @file       Log.h
    @brief      Logging

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/

#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

/*******************************************************************************
    Log
*******************************************************************************/
namespace Vela
{
    namespace Log
    {

        /**
            @typedef Vela::Log::LogStream
            @brief
        */
        #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
        typedef std::ostringstream LogStream;
        #elif defined(TARGET_EMBEDDED) || defined(TARGET_STM32)
        typedef class DummyStream
                {
                    public:
                        template<typename T>
                        DummyStream& operator<< (T val) { return *this; };
                } LogStream;
        #endif

        /**
            @typedef Vela::Log::IoManipOstream
            @brief
        */
        #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
        typedef std::ostream& (*IoManipOstream)( std::ostream& );
        #elif defined(TARGET_EMBEDDED) || defined(TARGET_STM32)
        typedef void* (*IoManipOstream)( void* );
        #endif

        /**
            @class Vela::Log::Logger
            @brief Logger class
        */
        class Logger
            #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
            : public ABI::Interface,
              public Language::NoCopy
            #endif
        {
            public:
                /**
                    @enum Vela::Log::Logger::LogLevel
                    @brief
                */
                enum LogLevel
                {
                    LL_ERROR,
                    LL_WARNING,
                    LL_INFO,
                    LL_DEBUG
                };

                /**
                    @fn Vela::Log::Logger::Logger()
                */
                Logger();

                /**
                    @fn Vela::Log::Logger::Logger()
                */
                Logger(LogLevel lvl);

                /**
                    @fn Vela::Log::Logger::~Logger()
                */
                #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
                virtual ~Logger();
                #else
                #warning "Not implemented for this toolchain."
                #endif

                /**
                    @fn Vela::Log::Logger::Self()
                */
                Logger const& Self() const;

                /**
                    @fn Vela::Log::Logger::Level()
                */
                LogLevel Level() const;

                /**
                    @fn Vela::Log::Logger::Stream()
                */
                LogStream const& Stream() const;

                /**
                    @fn Vela::Log::Logger::Write()
                */
                void Write(LogLevel lvl, const String& fmt, ...) const;

                /**
                    @fn Vela::Log::Logger::Trace()
                */
                void Trace(LogLevel lvl, const String& fmtt, const String& fmtu, ...) const;

                /**
                    @fn Vela::Log::Logger::operator<<
                */
                template<typename T>
                Logger& operator<<(const T &t)
                {
                    Publish(Level(), t);
                    return const_cast<Logger&>(Self());
                }

                /**
                    @fn Vela::Log::Logger::operator<<
                */
                Logger& operator<<(IoManipOstream mfp)
                {
                    Publish(Level(), mfp);
                    return const_cast<Logger&>(Self());
                }

            protected:
                /**
                    @fn Vela::Log::Logger::Publish()
                */
                #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
                Logger&  Publish(LogLevel lvl, const String& fmt, const va_list ap) const;
                #else
                #warning "Not implemented for this toolchain."
                #endif

                /**
                    @fn Vela::Log::Logger::Publish()
                */
                template <typename T>
                Logger&  Publish(LogLevel lvl, T const& t) const
                {
                    UNUSED(lvl);

                    #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
                    std::cerr << t;
                    #else
                    #warning "Not implemented for this toolchain."
                    UNUSED(t);
                    #endif

                    return const_cast<Logger&>(Self());
                }

                /**
                    @fn Vela::Log::Logger::Publish()
                */
                template <typename T>
                Logger&  Publish(LogLevel lvl, IoManipOstream mfp) const
                {
                    UNUSED(lvl);

                    #if defined(TARGET_WIN32) || defined(TARGET_POSIX)
                    std::cerr << mfp;
                    #else
                    #warning "Not implemented for this toolchain."
                    #endif

                    return const_cast<Logger&>(Self());
                }

            private:
                /**
                    @property Vela::Log::Logger::level_
                */
                LogLevel  level_;

                /**
                    @property Vela::Log::Logger::stream_
                */
                LogStream stream_;
        };

        /**
            @var Vela::Log::LoggerInstance
            @brief
        */
        extern Vela::Log::Logger LoggerInstance;

    }
}

/**
    @def LOG_ERROR
    @brief
*/
#define LOG_ERROR           Vela::Log::Logger::LL_ERROR

/**
    @def LOG_WARNING
    @brief
*/
#define LOG_WARNING         Vela::Log::Logger::LL_WARNING

/**
    @def LOG_INFO
    @brief
*/
#define LOG_INFO            Vela::Log::Logger::LL_INFO

/**
    @def LOG_DEBUG
    @brief
*/
#define LOG_DEBUG           Vela::Log::Logger::LL_DEBUG

/**
    @def LOG_INSTANCE
    @brief
*/
#if defined(TARGET_WIN32) || defined(TARGET_POSIX)
#define LOG_INSTANCE        Vela::Log::LoggerInstance
#else
#define LOG_INSTANCE        Vela::Log::LoggerInstance /*TODO: embedded stream*/
#endif

/**
    @def LOG
    @brief
*/
#if defined(TARGET_WIN32) || defined(TARGET_POSIX)
#define LOG(level, fmt, ...)    do { \
                                       Vela::Log::LoggerInstance.Write(level, fmt, ##__VA_ARGS__); \
                                } while (0)
#else
#define LOG(level, fmt, ...)    VOID_FUNCTION
#endif

/**
    @def TRACE
    @brief
*/
#if defined(TARGET_WIN32) || defined(TARGET_POSIX)
#define TRACE(level, fmt, ...)  do { \
                                       Vela::Log::LoggerInstance.Trace(level, TEXT("%s(%d):\t %s: "), \
                                               fmt, __FILE__, __LINE__, __PRETTY_FUNCTION__, ##__VA_ARGS__); \
                                } while (0)
#else
#define TRACE(level, fmt, ...)  VOID_FUNCTION
#endif

/**
    @def TRACE0
    @brief
*/
#if defined(TARGET_WIN32) || defined(TARGET_POSIX)
#define TRACE0(level)           do { \
                                       Vela::Log::LoggerInstance.Trace(level, TEXT("%s(%d):\t %s: "), \
                                               TEXT(""), __FILE__, __LINE__, __PRETTY_FUNCTION__); \
                                } while (0)
#else
#define TRACE0(level)           VOID_FUNCTION
#endif

/**
    @def LOG_ENDL
    @brief
*/
#if defined(TARGET_WIN32) || defined(TARGET_POSIX)
#define LOG_ENDL    std::endl
#else
#define LOG_ENDL    _T("\n")
#endif

#endif /*LOG_H_INCLUDED*/

