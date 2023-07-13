#include "vga.hpp"

void VGA_Terminal::clear() noexcept
{
    for (U32 r = 0; r < BUFFER_HEIGHT; ++r) {
        for (U32 c = 0; c < BUFFER_WIDTH; ++c) {
            buffer[r][c].color = m_color;
            buffer[r][c].input = ' ';
        }
    }
}

void VGA_Terminal::put(C8 c) noexcept
{
    switch (c) {
    case '\n':
        m_column = 0;
        ++m_row;
        break;
    default:
        VGA_Unit volatile& unit = buffer[m_row][m_column];
        unit.color = color();
        unit.input = c;
        ++m_column;
        break;
    }
    
    // Handle end of row.
    if (m_column >= BUFFER_WIDTH) {
        m_column = 0;
        ++m_row;
    }

    // Handle last row.
    if (m_row >= BUFFER_HEIGHT) {
        m_column = 0;
        m_row = 0;
    }
}

void VGA_Terminal::write(C8 const* s) noexcept
{
    for (U32 i = 0; s[0] != '\0'; ++i) {
        put(s[i]);
    }
}

