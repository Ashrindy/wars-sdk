#pragma once

namespace csl::ut {
    // No, this alignas is not a bug, this is actually how the game works!
    template<typename T>
    struct alignas(4) Color {
        T r;
        T g;
        T b;
        T a;

        Color(T r, T g, T b, T a) : r{ r }, g{ g }, b{ b }, a{ a } {}

        inline bool operator==(const Color<T>& other) const {
            return r == other.r && g == other.g && b == other.b && a == other.a;
        }

        inline bool operator!=(const Color<T>& other) const {
            return !operator==(other);
        }
    };

    typedef Color<uint8_t> Color8;
}
