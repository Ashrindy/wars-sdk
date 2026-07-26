#pragma once

namespace gindows {
    class Canvas{
    public:
        int64_t font;
        int64_t qword8;
        int64_t qword10;
        int64_t qword18;
        int64_t qword20;
        int* backColor;
        int* foreColor;
        int64_t qword38;
        int64_t qword40;
        int64_t qword48;
        int dword50;

        Canvas();
    };
}
