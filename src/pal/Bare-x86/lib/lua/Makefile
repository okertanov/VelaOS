#
#   @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
#   @license    BSD
#

LIB=libzlua.a

CC=gcc
CFLAGS=-O2 -pipe -Wall -Wextra -Werror -DLUA_COMPAT_ALL -DLUA_USE_POSIX
LDFLAGS=-L./
LDLIBS=-lm -lzlua

SOURCES =   lapi.c      \
            lauxlib.c   \
            lbaselib.c  \
            lbitlib.c   \
            lcode.c     \
            lcorolib.c  \
            lctype.c    \
            ldblib.c    \
            ldebug.c    \
            ldo.c       \
            ldump.c     \
            lfunc.c     \
            lgc.c       \
            linit.c     \
            liolib.c    \
            llex.c      \
            lmathlib.c  \
            lmem.c      \
            loadlib.c   \
            lobject.c   \
            lopcodes.c  \
            loslib.c    \
            lparser.c   \
            lstate.c    \
            lstring.c   \
            lstrlib.c   \
            ltable.c    \
            ltablib.c   \
            ltm.c       \
            lundump.c   \
            lvm.c       \
            lzio.c

OBJS = $(patsubst %.c,%.o,$(SOURCES))

all: $(LIB) zlua zluac

$(LIB): $(OBJS)
	ar rcs $@ $?

zlua: lua.o $(LIB)
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@ $(LDLIBS)

zluac: luac.o $(LIB)
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-@rm -f *.o *.a *.so zlua zluac

.PHONY: all clean

