#
#   @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
#   @license    BSD
#

include ../Makefile.common

COMMON_CFLAGS=-g -pipe -std=c99 -Wall -Wextra -Werror \
              -nostdlib -nostdinc -fno-builtin -nostartfiles -nodefaultlibs \
              -fno-stack-protector -fomit-frame-pointer -fno-exceptions \
              -fno-asynchronous-unwind-tables -fno-unwind-tables \
              -DZENO_KERNEL
COMMON_LDFLAGS=-g
COMMON_LDLIBS=

ifdef HOST_POSIX
HOST_CFLAGS=
HOST_LDFLAGS=
HOST_LDLIBS=
endif

ifdef HOST_WINDOWS
HOST_CFLAGS=-fno-leading-underscore
HOST_LDFLAGS=
HOST_LDLIBS=
endif

ifdef ARCH_X86
ARCH_CFLAGS=-mtune=native
ARCH_LDFLAGS=
ARCH_LDLIBS=
endif

ifdef ARCH_X64
ARCH_CFLAGS=-m32 -mtune=native
ARCH_LDFLAGS=-m elf_i386
ARCH_LDLIBS=
endif

CFLAGS=$(COMMON_CFLAGS) $(HOST_CFLAGS) $(ARCH_CFLAGS)
LDFLAGS=$(COMMON_LDFLAGS) $(HOST_LDFLAGS) $(ARCH_LDFLAGS)
LDLIBS=$(COMMON_LDLIBS) $(HOST_LDLIBS) $(ARCH_LDLIBS)

SOURCES =   start.c     \
            gdts.c      \
            idts.c      \
            gdt.c       \
            idt.c       \
            kernel.c    \
            video.c     \
            io.c        \
            timer.c     \
            memory.c    \
            hardware.c  \
            sched.c     \
            paravirt.c  \
            event.c     \
            util.c

OBJS = $(patsubst %.c,%.o,$(SOURCES))

all: kernel

kernel: kernel.img

kernel.img: kernel.raw
	$(CAT) ../bin/grub/stage1 ../bin/grub/stage2 ../bin/grub/pad750 $< > $@

kernel.raw: kernel.elf
	$(OBJCOPY) -O binary -S -j .text -j .rodata -j .rdata -j .data -j .bss --set-section-flags .bss=alloc,load,contents $< $@

kernel.elf: $(OBJS)
	$(LD) $(LDFLAGS) -Map kernel.map -T kernel.ld -o $@ $^
	$(STRIP) -d $@

%.o: %.s
	$(NASM) -f elf -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	-@$(RM) -f *.bin *.raw *.o *.elf *.img *.map *.lst

run: kernel.img
	qemu -no-reboot -m 512 -vga std -s -boot c -hda $<
#	qemu -vga std -s -kernel kernel.elf

help:
	-@echo "make clean all kernel run help"

.PHONY: all clean kernel run help

.SILENT: clean

