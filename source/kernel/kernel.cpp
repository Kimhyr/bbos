// #if defined(__linux__)
// #   error
// #endif
//  
// #if !defined(__i386__)
// #   error
// #endif

#include <kernel/vga/terminal.hpp>

extern "C" void kmain();

char to_ascii(uint8 i)
{
   if (i > 9) {
       return ' ';
   }
   return '0' + i;
}

void wait()
{
    uint32 count = 9999999;
    while (count--);
}

void kmain()
{
    using namespace kernel::vga;

    auto& t = Terminal::get();
    while (true) {
        for (uint i{0}; i < 10; ++i) {
            t.put(to_ascii(i));
            t.put('\n');
            wait();
        }
    }
}

