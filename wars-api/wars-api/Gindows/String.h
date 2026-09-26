#pragma once

namespace gindows {
    class String {
    public:
        char string0[0x20]; // std::basic_string<char, std::char_traits<char>, gindows::Allocator<char>>
        char string1[0x20]; // std::basic_string<char, std::char_traits<char>, gindows::Allocator<char>>
        int dword40;

        int compare(const char* other) const;
        const char* c_str() const;
        void set(const char* value);
        String& operator=(const char* str);

        String();
    };
}
