#pragma once

#include <core/types.h>

namespace kernel::vga
{

enum Color : uint8 
{
    black       = 0,
    blue        = 1,
    green       = 2,
    cyan        = 3,
    red         = 4,
    magenta     = 5,
    brown       = 6,
    light_grey  = 7,
    dark_grey   = 8,
    light_blue  = 9,
    light_cyan  = 10,
    light_red   = 11,
    light_brown = 12,
    white       = 13,
};

struct Attribute
{
    uint8 fg : 4,
          bg : 4;
};

struct Character
{
    char8     input;
    Attribute attribute;
};

}

