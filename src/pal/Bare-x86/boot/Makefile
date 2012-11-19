#
#   @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
#   @license    BSD
#

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

kernel.img: kernel.elf
	cat ../bin/grub/stage1 ../bin/grub/stage2 ../bin/grub/pad750 $< > $@

kernel.raw: kernel.elf
	objcopy $< -O binary $@

kernel.elf: $(OBJS)
	ld -g -m elf_i386 -Map kernel.map -T kernel.ld -o $@ $^
	strip -d $@

%.o: %.s
	nasm -g -f elf -o $@ $<

%.o: %.c
	gcc -std=c99 -g -m32 -Wall -Wextra -Werror -nostdlib -nostdinc -fno-builtin -nostartfiles -nodefaultlibs -fno-stack-protector -fomit-frame-pointer -fno-exceptions -fno-asynchronous-unwind-tables -fno-unwind-tables -c -o $@ $<

clean:
	-@rm -f *.bin *.raw *.o *.elf *.img *.map *.lst

run: kernel.img
	qemu -no-reboot -m 512 -vga std -s -boot c -hda $<
#	qemu -vga std -s -kernel kernel.elf

help:
	-@echo "make clean all kernel run help"

.PHONY: all clean kernel run help

.SILENT: clean

