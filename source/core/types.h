#pragma once

using int8  = __INT64_TYPE__;
using int16 = __INT16_TYPE__;
using int32 = __INT32_TYPE__;
using int64 = __INT64_TYPE__;

using uint8  = __UINT64_TYPE__;
using uint16 = __UINT16_TYPE__;
using uint32 = __UINT32_TYPE__;
using uint64 = __UINT64_TYPE__;

using uint = uint32;

using int_max  = __INTMAX_TYPE__;
using uint_max = __UINTMAX_TYPE__;

using int_fast8  = __INT_FAST8_TYPE__;
using int_fast16 = __INT_FAST16_TYPE__;
using int_fast32 = __INT_FAST32_TYPE__;
using int_fast64 = __INT_FAST64_TYPE__;

using uint_fast8  = __UINT_FAST8_TYPE__;
using uint_fast16 = __UINT_FAST16_TYPE__;
using uint_fast32 = __UINT_FAST32_TYPE__;
using uint_fast64 = __UINT_FAST64_TYPE__;

using int_least8  = __INT_LEAST8_TYPE__;
using int_least16 = __INT_LEAST16_TYPE__;
using int_least32 = __INT_LEAST32_TYPE__;
using int_least64 = __INT_LEAST64_TYPE__;

using uint_least8  = __UINT_LEAST8_TYPE__;
using uint_least16 = __UINT_LEAST16_TYPE__;
using uint_least32 = __UINT_LEAST32_TYPE__;
using uint_least64 = __UINT_LEAST64_TYPE__;

using intptr  = __INTPTR_TYPE__; 
using uintptr = __UINTPTR_TYPE__;

using size    = __SIZE_TYPE__;
using ptrdiff = __PTRDIFF_TYPE__;

using char8 = char;
using char16 = char16_t;
using char32 = char32_t;

using float16  = _Float16;
using float32  = float;
using float64  = double;
using float128 = __float128;

using bool8  = uint8;
using bool16 = uint16;
using bool32 = uint32;
using bool64 = uint64;

using nullptr_type = decltype(nullptr);

template<typename T>
concept INTEGER =
    requires (T v, T* p, void (*f)(T)) {
        reinterpret_cast<T>(v);
        f(0);
        p + v;
    };

enum byte : uint8 {};

constexpr
auto operator<<(byte b, INTEGER auto s) noexcept
    -> byte
{ return b << s; }

constexpr
auto operator>>(byte b, INTEGER auto s) noexcept
    -> byte
{ return b >> s; }

constexpr
auto operator|(byte l, byte r) noexcept
    -> byte
{ return l | r; }

constexpr
auto operator&(byte l, byte r) noexcept
    -> byte
{ return l & r; }

constexpr
auto operator^(byte l, byte r) noexcept
    -> byte
{ return l ^ r; }

constexpr
auto operator~(byte b) noexcept
    -> byte
{ return ~b; }

constexpr
auto operator<<=(byte& b, INTEGER auto s) noexcept
    -> byte&
{ return b = b << s; }

constexpr
auto operator>>=(byte& b, INTEGER auto s) noexcept
    -> byte&
{ return b = b >> s; }

constexpr
auto operator|=(byte& l, byte r) noexcept
    -> byte&
{ return l = l | r; }

constexpr
auto operator&=(byte& l, byte r) noexcept
    -> byte&
{ return l = l & r; }

constexpr
auto operator^=(byte& l, byte r) noexcept
    -> byte&
{ return l = l ^ r; }

