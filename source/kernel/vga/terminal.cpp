#include "terminal.h"

namespace kernel::vga 
{

auto& Terminal::buffer = *reinterpret_cast<Terminal::Buffer*>(0xb8000);

auto Terminal::clear() -> void
{
    for (BufferRow& r : buffer) {
        for (Character& c : r) {
            c.input = ' ';
        }
    }

    m_row = 0;
    m_column = 0;
}

auto Terminal::clear_line() -> void
{
    for (Character& c : buffer[row()]) {
        c.input = ' ';
    }

    m_column = 0;
}

auto Terminal::write(Char const* string) -> void
{
    while (*string != 0) {
        put(*string++);
    }
}

auto Terminal::put(Char input) -> void
{
    if (input == '\n') {
        add_line();
        return;
    }
    
    buffer[row()][column()] = {
        .input = input,
        .attribute = attribute()
    };

    if (column() == WIDTH - 1) {
        add_line();
        return;
    }

    ++m_column;
}

auto Terminal::add_line() -> void
{
    if (row() == HEIGHT - 1) {
        scroll();
        return;
    }

    ++m_row;
    m_column = 0;
}

auto Terminal::scroll() -> void
{
    for (Count i{1}; i < HEIGHT; ++i) {
        for (Count j{0}; j < WIDTH; ++j) {
            buffer[i - 1][j] = buffer[i][j];
        }
    }

    clear_line();
}

}

