#ifndef KOS_VGA_HPP
#define KOS_VGA_HPP

#include "types.hpp"

struct VGA_Unit
{
    U8 color;
    U8 input;
};

class VGA_Terminal
{
public:
    static constexpr U32 BUFFER_HEIGHT = 25;
    static constexpr U32 BUFFER_WIDTH = 80;
    using Buffer = VGA_Unit[BUFFER_HEIGHT][BUFFER_WIDTH];

    static constexpr U16 BUFFER_ADDRESS = 0xb800;

    volatile Buffer& buffer = *reinterpret_cast<Buffer*>(BUFFER_ADDRESS);
    
    VGA_Terminal()
    {
        clear();
    }

    [[nodiscard]] U32 row() const noexcept { return m_color; }
    [[nodiscard]] U32 column() const noexcept { return m_color; }
    [[nodiscard]] U8  color() const noexcept { return m_color; }

    void clear() noexcept;
    void put(C8 c) noexcept;
    void write(C8 const* s) noexcept;
    
private:
    U32 m_row    = 0;
    U32 m_column = 0;
    U8  m_color  = 0x0f;
};

#endif

