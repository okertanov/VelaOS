/**
    @file       PlatformDefs.h
    @brief      Platform definitions header

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/

#ifndef PLATFORMDEFS_H_INCLUDED
#define PLATFORMDEFS_H_INCLUDED

/*******************************************************************************
    OS Definitions
*******************************************************************************/
/**
    @def VELA_NAME
    @brief
*/
#define VELA_NAME               TEXT("VelaOS")

/**
    @def VELA_VERSION
    @brief
*/
#define VELA_VERSION            (Vela::Platform::V_01_00)

/*******************************************************************************
    Platform Configuration
*******************************************************************************/

#undef VELA_PLATFORM

/**
    @def VELA_PLATFORM
    @brief
*/
#if defined(WIN32) || defined (_WIN32) || defined(__WIN32__) || \
    defined(__CYGWIN__) || defined(__MINGW32__)
#define VELA_PLATFORM   VELA_PLATFORM_WIN32

#elif defined(WIN64) || defined(_WIN64)
#define VELA_PLATFORM   VELA_PLATFORM_WIN64

#elif defined(__posix)   || defined(__posix__) || \
      defined(__unix)    || defined(__unix__)  || \
      defined(__linux)   || defined(linux)     || \
      defined(__FreeBSD__)  || \
      defined(__QNX__)      || \
      defined(__APPLE__) || defined(__MACH__)
#define VELA_PLATFORM   VELA_PLATFORM_POSIX

#elif defined(__TASKING__) || defined (__ICCARM__) || \
      defined(__CC_ARM)    || (defined(__GNUC__) && defined(__arm__))
#define VELA_PLATFORM   VELA_PLATFORM_STM32

#else
#define VELA_PLATFORM   VELA_PLATFORM_UNKNOWN
#error "VELA_PLATFORM = VELA_PLATFORM_UNKNOWN"
#endif

/*******************************************************************************
    Platform defines
*******************************************************************************/
/**
    @def QUOTE
    @brief
*/
#ifndef QUOTE
    #define QUOTE(A) #A
#endif

/**
    @def CONCATENATE
    @brief
*/
#ifndef CONCATENATE
    #define CONCATENATE(A, B) A ## B
#endif

/**
    @def LIKELY
    @brief
    @see http://kerneltrap.org/node/4705
*/
#ifdef __GNUC__
    #define LIKELY(C)       __builtin_expect((C), 1)
#else
    #define LIKELY(C)       (C)
#endif

/**
    @def UNLIKELY
    @brief
    @see http://kerneltrap.org/node/4705
*/
#ifdef __GNUC__
    #define UNLIKELY(C)       __builtin_expect((C), 0)
#else
    #define UNLIKELY(C)       (C)
#endif

/**
    @def UNUSED
    @brief
*/
#ifndef UNUSED
    #define UNUSED(X) (void)X
#endif

/**
    @def VOID_FUNCTION
    @brief
*/
#ifndef VOID_FUNCTION
    #define VOID_FUNCTION   ((void)0)
#endif

/**
    @def EXIT_SUCCESS
    @brief
*/
#ifndef EXIT_SUCCESS
    #define EXIT_SUCCESS    0
#endif

/**
    @def EXIT_FAILURE
    @brief
*/
#ifndef EXIT_FAILURE
    #define EXIT_FAILURE    1
#endif

/**
    @def TEXT
    @brief
*/
#ifdef UNICODE
    #ifndef TEXT
        #define TEXT(T)     L#T
    #endif
#else
    #ifndef TEXT
        #define TEXT(T)     T
    #endif
#endif

/**
    @def _T
    @brief
*/
#ifndef _T
    #define _T(T)   TEXT(T)
#endif

/**
    @def OFFSETOF
    @brief
*/
#define OFFSETOF(type, member)  __builtin_offsetof (type, member)

/**
    @def __attribute__
    @brief
*/
#ifndef __GNUC__
#  define  __attribute__(a)
#endif

/**
    @def ATTR_NORETURN
    @brief
*/
#define ATTR_NORETURN       __attribute__((noreturn))

/**
    @def ATTR_DEPRECATED
    @brief
*/
#define ATTR_DEPRECATED     __attribute__((deprecated))

/**
    @def ATTR_INTERRUPT
    @brief
*/
#define ATTR_INTERRUPT      __attribute__((interrupt))

/**
    @def ATTR_CONST
    @brief
*/
#define ATTR_CONST          __attribute__((const))

/**
    @def ATTR_NAKED
    @brief
*/
#define ATTR_NAKED          __attribute__((naked))

/**
    @def ATTR_PURE
    @brief
*/
#define ATTR_PURE           __attribute__((pure))

/**
    @def ATTR_WEAK
    @brief
*/
#define ATTR_WEAK           __attribute__((weak))

/**
    @def ATTR_HOT
    @brief
*/
#define ATTR_HOT            __attribute__((hot))

/**
    @def ATTR_COLD
    @brief
*/
#define ATTR_COLD           __attribute__((cold))

/**
    @def ATTR_USED
    @brief
*/
#define ATTR_USED           __attribute__((used))

/**
    @def ATTR_CONSTRUCTOR
    @brief
*/
#define ATTR_CONSTRUCTOR    __attribute__((constructor))

/**
    @def ATTR_DESTRUCTOR
    @brief
*/
#define ATTR_DESTRUCTOR     __attribute__((destructor))

/**
    @def ATTR_CLEANUP
    @brief
*/
#define ATTR_CLEANUP(FP)    __attribute__((cleanup(FP)))

/**
    @def ATTR_ALIAS
    @brief
*/
#define ATTR_ALIAS(F)       __attribute__((alias(QUOTE(F))));

/**
    @def ATTR_WEAKREF
    @brief
*/
#define ATTR_WEAKREF(F)     __attribute__((weakref(QUOTE(F))));

#if !defined(TARGET_WIN32) && !defined(TARGET_POSIX)
/**
    @def uintptr_t
    @brief
*/
#ifndef NULL
#define NULL ((void*)0)
#endif

/**
    @def bool
    @brief
*/
#ifndef __cplusplus
#ifndef bool
#warning "Redefining bool!"
#define bool  unsigned int
#endif
#endif

/**
    @def true
    @brief
*/
#ifndef __cplusplus
#ifndef true
#warning "Redefining true!"
#define true    (1)
#endif
#endif

/**
    @def false
    @brief
*/
#ifndef __cplusplus
#ifndef false
#warning "Redefining false!"
#define false   (!true)
#endif
#endif

/**
    @def size_t
    @brief
*/
#ifndef size_t
#warning "Redefining size_t!"
typedef __SIZE_TYPE__ size_t;
#define size_t size_t
#endif

/**
    @def time_t
    @brief
*/
#ifndef time_t
#warning "Redefining time_t!"
typedef unsigned long time_t;
#define time_t time_t
#endif

/**
    @def intptr_t
    @brief
*/
#ifndef intptr_t
typedef long int intptr_t;
#define intptr_t intptr_t
#endif

/**
    @def uintptr_t
    @brief
*/
#ifndef uintptr_t
typedef unsigned long int uintptr_t;
#define uintptr_t uintptr_t
#endif

/**
    @def caddr_t
    @brief
*/
#ifndef caddr_t
typedef char* caddr_t;
#define caddr_t caddr_t
#endif

/**
    @def dev_t
    @brief
*/
#ifndef dev_t
typedef unsigned long int dev_t;
#define dev_t dev_t
#endif

/**
    @def ino_t
    @brief
*/
#ifndef ino_t
typedef unsigned long int ino_t;
#define ino_t ino_t
#endif

/**
    @def mode_t
    @brief
*/
#ifndef mode_t
typedef unsigned int mode_t;
#define mode_t mode_t
#endif

/**
    @def nlink_t
    @brief
*/
#ifndef nlink_t
typedef unsigned int nlink_t;
#define nlink_t nlink_t
#endif

/**
    @def uid_t
    @brief
*/
#ifndef uid_t
typedef unsigned int uid_t;
#define uid_t uid_t
#endif

/**
    @def gid_t
    @brief
*/
#ifndef gid_t
typedef unsigned int gid_t;
#define gid_t gid_t
#endif

/**
    @def loff_t
    @brief
*/
#ifndef loff_t
typedef unsigned long int loff_t;
#define loff_t loff_t
#endif

/**
    @def stat
    @brief
*/
#ifndef stat
struct stat
{
  dev_t st_dev;
  ino_t st_ino;
  mode_t st_mode;
  nlink_t st_nlink;
  uid_t st_uid;
  gid_t st_gid;
  dev_t st_rdev;
  loff_t st_size;
  time_t st_atime;
  time_t st_mtime;
  time_t st_ctime;
};
#endif

/**
    @def va_list
    @brief
*/
#ifndef va_list
#warning "Redefining va_list and co!"
typedef __builtin_va_list va_list;
#define va_list va_list
#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)
#endif

#endif /*!defined(TARGET_WIN32) && !defined(TARGET_POSIX)*/

#endif /*PLATFORMDEFS_H_INCLUDED*/

