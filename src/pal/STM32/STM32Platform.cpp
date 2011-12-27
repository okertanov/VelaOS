/**
    @file       STM32Platform.cpp
    @brief      STM32 platform abstraction layer implementation

    @author     Oleg Kertanov <okertanov@gmail.com>
    @date       Oct 2011
    @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
    @license    BSD
    @see LICENSE file
*/

#include "core/Platform.h"
#include "STM32Platform.h"

/*******************************************************************************
    C++ PAL
*******************************************************************************/
namespace Vela
{
    namespace PAL
    {

    }
}

extern unsigned long _estack;

ATTR_ISR_VECTOR ISRVectorArray =
{
    (ISRCallback)((unsigned long)&_estack),
    Reset_Handler(),
    0
};

#if defined(VELA_OWN_NEW_DELETE)
/**
    @fn ::operator new()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
void* operator new(size_t n)
{
    return ::malloc(n);
}

/**
    @fn ::operator new()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
void* operator new[](size_t n)
{
    return ::malloc(n);
}

/**
    @fn ::operator delete()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
void  operator delete(void* p)
{
    ::free(p);
}

/**
    @fn ::operator delete()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
void  operator delete[](void* p)
{
    ::free(p);
}

/**
    @fn ::operator new()
    @brief
    @note placement version

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
void* operator new(size_t, void* p)
{
    return p;
}

/**
    @fn ::operator new()
    @brief
    @note placement version

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
void* operator new[](size_t, void* p)
{
    return p;
}

/**
    @fn ::operator delete()
    @brief
    @note placement version

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
void  operator delete(void*, void*)
{
}

/**
    @fn ::operator delete()
    @brief
    @note placement version

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
void  operator delete[](void*, void*)
{
}
#endif //#if defined(VELA_OWN_NEW_DELETE)

/*******************************************************************************
    C PAL
*******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

/**
    @fn Vela_Reset_Handler()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
static void Vela_Reset_Handler()
{
    //TODO: Implementation
}

/**
    @fn Vela_exit()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
static void Vela_exit(int code)
{
    //TODO: Implementation
    UNUSED(code);
}

/**
    @fn Vela_sbrk()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
static caddr_t Vela_sbrk(intptr_t increment)
{
    //TODO: Implementation

    UNUSED(increment);

    return 0;
}

/**
    @fn Vela_kill()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
static int Vela_kill(int pid, int sig)
{
    //TODO: Implementation

    UNUSED(pid), UNUSED(sig);

    return 0;
}

/**
    @fn Vela_getpid()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
static int Vela_getpid(void)
{
    //TODO: Implementation

    return 0;
}

/**
    @fn Vela_isatty()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
static int Vela_isatty(int file)
{
    //TODO: Implementation

    UNUSED(file);

    return 0;
}

/**
    @fn Vela_open()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
static int Vela_open(const char *name, int flags, int mode)
{
    //TODO: Implementation

    UNUSED(name), UNUSED(flags), UNUSED(mode);

    return 0;
}

/**
    @fn Vela_close()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
static int Vela_close(int file)
{
    //TODO: Implementation

    UNUSED(file);

    return 0;
}

/**
    @fn Vela_read()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
static int Vela_read(int  file, char *ptr, int len)
{
    //TODO: Implementation

    UNUSED(file), UNUSED(ptr), UNUSED(len);

    return 0;
}

/**
    @fn Vela_write()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
static int Vela_write(int file, char *ptr, int len)
{
    //TODO: Implementation

    UNUSED(file), UNUSED(ptr), UNUSED(len);

    return 0;
}

/**
    @fn Vela_fstat()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
static int Vela_fstat(int file, struct stat *st)
{
    //TODO: Implementation

    UNUSED(file), UNUSED(st);

    return 0;
}

/**
    @fn Vela_stat()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
static int Vela_stat(char *file, struct stat *st)
{
    //TODO: Implementation

    UNUSED(file), UNUSED(st);

    return 0;
}

/**
    @fn Vela_lseek()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
static int Vela_lseek(int file, int ptr, int dir)
{
    //TODO: Implementation

    UNUSED(file), UNUSED(ptr), UNUSED(dir);

    return 0;
}

/**
    @fn Vela_malloc()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
void* Vela_malloc(size_t size)
{
    //TODO: Implementation

    UNUSED(size);

    return (NULL);
}

/**
    @fn Vela_free()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
void Vela_free(void *ptr)
{
    //TODO: Implementation

    UNUSED(ptr);
}

/**
    @fn Vela_memcpy()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
void* Vela_memcpy(void *dst, const void *src, size_t num)
{
    //TODO: Implementation

    UNUSED(dst), UNUSED(src), UNUSED(num);

    return (NULL);
}

/**
    @fn Vela_abort()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
void Vela_abort (void)
{
    //TODO: Implementation
}

/**
    @fn Vela__cxa_pure_virtual()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
static void Vela__cxa_pure_virtual()
{
    //TODO: Implementation
}

/**
    @fn Vela__fini()
    @brief

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
static void Vela__fini(void)
{
    //TODO: Implementation
}


/**
    @fn Reset_Handler()
    @brief STM32 EABI Stubs
    @see STM32 startup code

    @param[in]
    @param[out]
    @param[in,out]
    @return
*/
void ATTR_USED Reset_Handler()       ATTR_INTERRUPT ATTR_ALIAS( Vela_Reset_Handler );

/**
    @brief ARM EABI stubs
    @see http://sourceware.org/newlib/libc.html#Stubs
*/
void _exit(int code)                                ATTR_ALIAS( Vela_exit   );
caddr_t _sbrk(intptr_t increment)                   ATTR_ALIAS( Vela_sbrk   );
int _kill(int pid, int sig)                         ATTR_ALIAS( Vela_kill   );
int _getpid(void)                                   ATTR_ALIAS( Vela_getpid );
int _isatty(int file)                               ATTR_ALIAS( Vela_isatty );
int _open(const char *name, int flags, int mode)    ATTR_ALIAS( Vela_open   );
int _close(int file)                                ATTR_ALIAS( Vela_close  );
int _read(int  file, char *ptr, int len)            ATTR_ALIAS( Vela_read   );
int _write(int file, char *ptr, int len)            ATTR_ALIAS( Vela_write  );
int _fstat(int file, struct stat *st)               ATTR_ALIAS( Vela_fstat  );
int _stat(char *file, struct stat *st)              ATTR_ALIAS( Vela_stat   );
int _lseek(int file, int ptr, int dir)              ATTR_ALIAS( Vela_lseek  );

/**
    @brief GCC runtime stubs
*/
void* malloc(size_t size)                           ATTR_ALIAS( Vela_malloc );
void  free(void *ptr )                              ATTR_ALIAS( Vela_free   );

void* memcpy(void *dst, const void *src,
        size_t num)                                 ATTR_ALIAS( Vela_memcpy );
void abort (void)                                   ATTR_ALIAS( Vela_abort );

/**
    @brief G++ EABI stubs
*/
void __cxa_pure_virtual()                           ATTR_ALIAS( Vela__cxa_pure_virtual );

void *__dso_handle = NULL;

void _fini(void)                                    ATTR_ALIAS( Vela__fini );

#ifdef __cplusplus
}
#endif /*__cplusplus*/

