// Make sure we are compiling to x86-elf
#if defined(__linux__)
#   error "Being compiled without a cross-compiler."
#elif !defined(__i386__)
#   error "Not being compiled with an x86-elf compiler."
#endif

#include "vga.hpp"

extern "C" void kmain(void)
{
    VGA_Terminal t;
    t.write("Hello, World! - the Kernel\n");
}
