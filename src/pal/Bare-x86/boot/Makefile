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
	ld -m elf_i386 -Map kernel.map -T kernel.ld -o $@ $^

kernel.o: kernel.c
	gcc -m32 -Wall -Wextra -Werror -nostdlib -nostdinc -fno-builtin -nostartfiles -nodefaultlibs -fno-stack-protector -o $@ $<

start.o: start.s
	nasm -f elf -o $@ $<

clean:
	-@rm -f *.bin *.o *.elf *.img *.map *.lst

run: kernel.img
	/c/tools/qemu/qemu-system-i386w.exe -L /c/tools/qemu/Bios -vga std $<
#	/c/tools/qemu/qemu-system-i386w.exe -L /c/tools/qemu/Bios -vga std -boot c -hda kernel.bin
#	/c/tools/qemu/qemu-system-i386w.exe -L /c/tools/qemu/Bios -vga std -boot c -hda kernel.img

help:
	-@echo "make clean all kernel run help"

.PHONY: all clean kernel run help

.SILENT: clean

