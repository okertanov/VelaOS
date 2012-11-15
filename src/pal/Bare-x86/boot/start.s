;
;   @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
;   @license    BSD
;

; To produce 32 bits code
bits 32

; Making entry point visible to linker
global start, _start

; kmain is defined in kernel.c
extern _kmain

; Initial kernel stack space (16Kb)
STACKSIZE equ 0x4000

; Load base address
; must be >= 1Mb
IMAGE_LOAD_BASE equ 0x00100000

; Direct video memory address
VIDEORAM_BASE equ 0xB8000

; Multiboot header - see GRUB docs for details
; http://www.gnu.org/software/grub/manual/multiboot/multiboot.html#boot_002eS

; Mmagic number - lets bootloader find the header
MULTIBOOT_HEADER_MAGIC     equ  0x1BADB002

; Multiboot 'flag' field
; 0x00010003 - not an elf, or 0x00000003 - an elf executable
MULTIBOOT_HEADER_FLAGS     equ  0x00010003

; Multiboot checksum required
MULTIBOOT_HEADER_CHECKSUM  equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)

; Code section
section .text

; Align 32 bits boundary
align 4

; Main loader code
start:
_start:
    ; When use own bootloader
    jmp     multiboot_entry

    ; Multiboot header
multiboot_header:
    dd MULTIBOOT_HEADER_MAGIC               ; Magic number
    dd MULTIBOOT_HEADER_FLAGS               ; Flags
    dd MULTIBOOT_HEADER_CHECKSUM            ; Checksum
    dd IMAGE_LOAD_BASE + multiboot_header   ; Header adress
    dd IMAGE_LOAD_BASE                      ; Load adress
    dd 00                                   ; Load end adress : not necessary
    dd 00                                   ; Bss end adress : not necessary
    dd IMAGE_LOAD_BASE + multiboot_entry    ; Entry adress

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

    ; Pass multiboot arguments as:
    ;     int kmain(unsigned int magic, void* mb_info)
    push ebx ; Multiboot info structure
    push eax ; Multiboot magic number

    ; Then call kernel's main code
    call _kmain

    ; Show Message
show_message:
    mov edi, VIDEORAM_BASE
    mov esi, IMAGE_LOAD_BASE
    add esi, boot_msg ; offset from base
msg:
    mov byte al, [esi]
    cmp al, 0
    je  terminate
    mov ah, 0xa0
    mov word [edi], ax
    add edi, 2
    inc esi
    jmp msg

    ; Terminate
terminate:
    cli
hang_loop:
    ; Halt machine when kernel returns
    hlt
    jmp hang_loop

    ; Local data
boot_msg:
    db "Booting...", 0
halt_message:
    db "Halted.", 0

; Block Started by Symbol
; uninitialized data section (zeroed by default)
section .bss

; Reserve 16k stack on a doubleword boundary
stack:
    align 4
    resb STACKSIZE

