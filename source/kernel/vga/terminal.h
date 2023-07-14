#pragma once

#include <core/types.h>

#include <kernel/vga/character.h>

namespace kernel::vga
{

class Terminal
{
public:
    using This  = Terminal;
    using Count = uint8;
    using Char  = char8;

    static constexpr Count HEIGHT = 25;
    static constexpr Count WIDTH  = 80;

    using BufferRow = Character[WIDTH];
    using Buffer    = BufferRow[HEIGHT];
   
    static Buffer& buffer;

    [[nodiscard]]
    static auto get() -> This&
    {
        static This self;
        return self; 
    }

    [[nodiscard]]
    auto row() const -> Count 
    {
        return m_row;
    }
    
    [[nodiscard]]
    auto column() const -> Count 
    {
        return m_column;
    }
    
    [[nodiscard]]
    auto attribute() const -> Attribute
    {
        return m_attribute;
    }

    auto clear      () -> void;
    auto clear_line () -> void;
    auto write      (Char const* string) -> void;
    auto put        (Char input) -> void;
    auto add_line   () -> void;
    auto scroll     () -> void;

private:
    Count     m_row{0};
    Count     m_column{0};
    Attribute m_attribute{
        .fg = Color::light_grey,
        .bg = Color::black,
    };

    Terminal()
    {
        clear();
    }
};

}

#endif

