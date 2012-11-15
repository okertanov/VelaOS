#
#   @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
#   @license    BSD
#

all: kernel

kernel: kernel.img

kernel.img: kernel.elf
	cat ../bin/grub/stage1 ../bin/grub/stage2 ../bin/grub/pad750 $< > $@

kernel.bin: kernel.elf
	objcopy $< -O binary $@

kernel.elf: start.o kernel.o
	ld -g -m elf_i386 -Map kernel.map -T kernel.ld -o $@ $^

start.o: start.s
	nasm -g -f elf -o $@ $<

kernel.o: kernel.c
	gcc -g -m32 -Wall -Wextra -Werror -nostdlib -nostdinc -fno-builtin -nostartfiles -nodefaultlibs -fno-stack-protector -fomit-frame-pointer -fno-exceptions -fno-asynchronous-unwind-tables -fno-unwind-tables -c -o $@ $<

clean:
	-@rm -f *.bin *.o *.elf *.img *.map *.lst

run: kernel.img
	qemu -vga std -s $<
#	qemu -vga std -s -kernel kernel.elf

help:
	-@echo "make clean all kernel run help"

.PHONY: all clean kernel run help

.SILENT: clean

