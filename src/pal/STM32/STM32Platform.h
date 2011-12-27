/**
    @file       STM32Platform.h
    @brief      STM32 platform abstraction layer

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/

#ifndef STM32PLATFORM_H_INCLUDED
#define STM32PLATFORM_H_INCLUDED

/**
    @def ATTR_ISR_VECTOR
    @brief
*/
#define ATTR_ISR_VECTOR __attribute__((section(".isr_vector"), used))

/**
    @typedef ISRVectorType
    @brief
*/
typedef void (*const ISRCallback)(void);

typedef ISRCallback ISRVectorArray[];

/*******************************************************************************
    C++ PAL
*******************************************************************************/
namespace Vela
{
    namespace PAL
    {

    }
}

#if defined(VELA_OWN_NEW_DELETE)
/**
    @fn ::operator new()
*/
void* operator new  (size_t n);

/**
    @fn ::operator new()
*/
void* operator new[](size_t n);

/**
    @fn ::operator delete()
*/
void  operator delete  (void* p);

/**
    @fn ::operator delete()
*/
void  operator delete[](void* p);

/**
    @fn ::operator new()
    @note placement version
*/
void* operator new(size_t, void* p);

/**
    @fn ::operator new()
    @note placement version
*/
void* operator new[](size_t, void* p);

/**
    @fn ::operator delete()
    @note placement version
*/
void  operator delete  (void*, void*);

/**
    @fn ::operator delete()
    @note placement version
*/
void  operator delete[](void*, void*);
#endif //#if defined(VELA_OWN_NEW_DELETE)

/*******************************************************************************
    C PAL
*******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

extern void _exit(int code);
extern caddr_t _sbrk(intptr_t increment);
extern int _kill(int pid, int sig);
extern int _getpid(void);
extern int _isatty(int file);
extern int _open(const char *name, int flags, int mode);
extern int _close(int file);
extern int _read(int  file, char *ptr, int len);
extern int _write(int file, char *ptr, int len);
extern int _fstat(int file, struct stat *st);
extern int _stat(char *file, struct stat *st);
extern int _lseek(int file, int ptr, int dir);

extern void* malloc( size_t size);
extern void free(void *ptr);
extern void* memcpy(void *dst, const void *src, size_t num);
extern void abort (void);

extern void _fini (void);
extern void __cxa_pure_virtual();
extern void *__dso_handle;

#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif /*STM32PLATFORM_H_INCLUDED*/

