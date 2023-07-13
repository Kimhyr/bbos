.extern kmain
.global start

#
# Multiboot
#
.set MULTIBOOT_MAGIC, 0x1badb002
.set MULTIBOOT_FLAGS, (1 << 0) | (1 << 1) # Load modules on page boundaries, and
                                          # provide a memory map.
.set MULTIBOOT_CHECKSUM, (0 - (MULTIBOOT_MAGIC + MULTIBOOT_FLAGS))

.section .multiboot
        .align 4
        .long MULTIBOOT_MAGIC
        .long MULTIBOOT_FLAGS
        .long MULTIBOOT_CHECKSUM

#
# Stack 
#
.section .bss
    .align 16
    # Allocate 4KiB for the stack.
    stack_bottom:
        .skip 4096
    stack_top:

#
# Text
#
.section .text
    start:
        # Initiate the stack.
        mov     $stack_top, %esp
        call    kmain
    hang:
        # Handle the circumstances of `kmain` returning. 
        cli # Disable CPU interrupts   
        hlt
        jmp     hang

