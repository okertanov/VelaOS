// see http://sourceware.org/ for details
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>
#include "rtc.h"

void _exit(int i);
int _open(const char *name, int flags, int mode);
int _read(int file, char *ptr, int len);
int _write(int file, char *buffer, unsigned int count);
int _lseek(int file, int ptr, int dir);
int _fstat(int file, struct stat *st);
int _link(char *old, char *new);
int _unlink(char *name);
int _stat(char *file, struct stat *st);
int _close(int file);
int _execve(char *name, char **argv, char **env);
int _fork();
int _getpid();
int _isatty(int file);
int _kill(int pid, int sig);
caddr_t _sbrk(int incr);
int times(struct tm *buf);
int _wait(int *status);

#undef errno
extern int errno;
char *__env[1] = {0};
char **__environ = __env;
extern unsigned int _heap;
extern unsigned int _eheap;
static caddr_t heap = NULL;


void _exit(int i)
{
	printf("Program exit with code %d", i);
	while (1);
}

extern int putChar(int ch);

int _write(int file, char *buffer, unsigned int count)
{
	register unsigned int i;
	(void)file;
	for (i = 0; i < count; ++i)
		putChar(*buffer++);
	return count;
}

int _close(int file)
{
	(void)file;
	return -1;
}

int _fstat(int file, struct stat *st)
{
	(void)file;
	st->st_mode = S_IFCHR;
	return 0;
}

int _isatty(int file)
{
	(void)file;
	return 1;
}

int _lseek(int file, int ptr, int dir)
{
	(void)file;
	(void)ptr;
	(void)dir;
	return 0;
}

int _read(int file, char *ptr, int len)
{
	(void)file;
	(void)ptr;
	(void)len;
	return 0;
}

caddr_t _sbrk(int incr)
{
	caddr_t prevHeap;
	caddr_t nextHeap;

	if (heap == NULL)
	{ // first allocation
		heap = (caddr_t) & _heap;
	}

	prevHeap = heap;

	// Always return data aligned on a 8 byte boundary
	nextHeap = (caddr_t) (((unsigned int) (heap + incr) + 7) & ~7);

	// Check enough space and there is no collision with stack coming the other way
	// if stack is above start of heap
	if (nextHeap >= (caddr_t) & _eheap)
	{
		errno = ENOMEM;
		return NULL; // error - no more memory
	}
	else
	{
		heap = nextHeap;
		return (caddr_t) prevHeap;
	}
}

int _open(const char *name, int flags, int mode)
{
	(void)name;
	(void)flags;
	(void)mode;
	return -1;
}

int _link(char *old, char *new)
{
	(void)old;
	(void)new;
	errno = EMLINK;
	return -1;
}

int _unlink(char *name)
{
	(void)name;
	errno = ENOENT;
	return -1;
}

int _stat(char *file, struct stat *st)
{
	(void)file;
	st->st_mode = S_IFCHR;
	return 0;
}

int _execve(char *name, char **argv, char **env)
{
	(void)name;
	(void)argv;
	(void)env;
	errno = ENOMEM;
	return -1;
}

int _fork()
{
	errno = EAGAIN;
	return -1;
}

int _getpid()
{
	return 1;
}

int _kill(int pid, int sig)
{
	(void)pid;
	(void)sig;
	errno = EINVAL;
	return (-1);
}

int times(struct tm *buf)
{
	(void)buf;
	return -1;
}

int _wait(int *status)
{
	(void)status;
	errno = ECHILD;
	return -1;
}

int _gettimeofday (struct timeval * tp, void * tzvp)
{
  struct timezone *tzp = tzvp;
  if (tp)
    {
      tp->tv_sec = rtc_get_counter();
      tp->tv_usec = 0;
    }

  /* Return fixed data for the timezone.  */
  if (tzp)
    {
      tzp->tz_minuteswest = 0;
      tzp->tz_dsttime = 0;
    }

  return 0;
}

