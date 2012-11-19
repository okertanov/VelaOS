;
;   @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
;   @license    BSD
;

; To produce 32 bits code
bits 32

; Making entry point visible to linker
global start

; sys_main is defined in kernel.c
extern sys_main

; linker externals
extern __image_start__, __text_start__, __data_end__, __bss_start__, __bss_end__

; Initial kernel stack space (16Kb)
STACKSIZE equ 0x4000

; Load base address, must be >= 1Mb
; Extended memory:
; Start: 0x00100000 End: 0x00EFFFFF Size: 0x00E00000 (14 MiB)
IMAGE_LOAD_BASE equ 0x00100000

; Direct video memory address
VIDEORAM_BASE equ 0x000B8000

; Multiboot header - see GRUB docs for details
; http://www.gnu.org/software/grub/manual/multiboot/multiboot.html#boot_002eS

; Mmagic number - lets bootloader find the header
MULTIBOOT_HEADER_MAGIC     equ  0x1BADB002

; Multiboot 'flag' field
; 0x00010003 - not an elf, or
; 0x00000003 - an elf executable, or
; 0x00010007 - with kludge and video mode info
MULTIBOOT_HEADER_FLAGS     equ  0x00010003

; Multiboot checksum required
MULTIBOOT_HEADER_CHECKSUM  equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)

; Use Multiboot header
%define USE_MILTIBOOT_HEADER    1

; Use a.out cludge
%define USE_AOUT_KLUDGE         1

; Use graphics cludge
%define USE_GRAPHICS_KLUDGE     1

; Use raw entry for non-multiboot loaders
%define USE_RAW_ENTRY           1

; Code section
section .text

; Skip header when using raw startup
%ifdef USE_RAW_ENTRY
raw_entry:
    jmp start
.end:
%endif

; Align multiboot header to 32-bit boundary
align 4

; Multiboot header
%ifdef USE_MILTIBOOT_HEADER
multiboot_header:
    dd MULTIBOOT_HEADER_MAGIC               ; Magic number
    dd MULTIBOOT_HEADER_FLAGS               ; Flags
    dd MULTIBOOT_HEADER_CHECKSUM            ; Checksum
%ifdef USE_AOUT_KLUDGE
    dd multiboot_header                     ; Header adress
    dd __text_start__                       ; Load adress
    dd __data_end__                         ; Load end adress: not necessary
    dd __bss_end__                          ; Bss end adress: not necessary
    dd multiboot_entry                      ; Entry adress
%endif
%ifdef USE_GRAPHICS_KLUDGE
    dd  1                                   ; Mode: EGA-standard text mode
    dd 00                                   ; Width: not specified
    dd 00                                   ; Height: not specified
    dd 00                                   ; Depth: not specified
%endif
.end:
%endif

; Main loader code
start:
    ; When use own bootloader
    jmp multiboot_entry
.end:

    ; Multiboot entry
multiboot_entry:

    ; Mask interrupts
    cli

    ; Set up the stack
    mov esp, stack + STACKSIZE
    mov ebp, esp

    ; Reset EFLAGS
    push   0
    popf

    ; Clear flags
    clc ; Carry flag
    cld ; Direction flag

    ; Pass multiboot arguments as:
    ;     int sys_main(unsigned int magic, void* mb_info)
    push ebx ; Multiboot info structure
    push eax ; Multiboot magic number

    ; Then call kernel's main code
    call sys_main

    ; Terminate
terminate:
    cli
hang_loop:
    ; Halt machine when kernel returns
    hlt
    jmp hang_loop
.end:

; Local data
section .data
boot_msg:
    db "Booting...", 0
.end:
halt_msg:
    db "Halted.", 0
.end:

; Block Started by Symbol
; uninitialized data section (zeroed by default)
section .bss

; Reserve 16k stack on a doubleword boundary
stack:
    align 4
    resb STACKSIZE
.end:

