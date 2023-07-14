.extern kmain
.global _start

/* Multiboot constants */
.set MULTIBOOT_MAGIC,	    0x1BADB002 
.set MULTIBOOT_ALIGN,	    1 << 0
.set MULTIBOOT_MEMORY,	    1 << 1
.set MULTIBOOT_FLAGS,       MULTIBOOT_ALIGN | MULTIBOOT_MEMORY
.set MULTIBOOT_CHECKSUM,    -(MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)

/* Multiboot header */
.section .multiboot
    .align 4
    .long MULTIBOOT_MAGIC
    .long MULTIBOOT_FLAGS
    .long MULTIBOOT_CHECKSUM

/* The Stack */
.section .bss
    .align 16
    stack_bottom:
        .skip 16384
    stack_top:

.section .text
    .global _start
    .type   _start, @function
    _start:
        mov     $stack_top, %esp
        call    kmain
    loop:
        cli
        hlt
        jmp     loop

.size _start, . - _start

