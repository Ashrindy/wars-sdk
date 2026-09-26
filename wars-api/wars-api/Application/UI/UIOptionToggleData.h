#pragma once

namespace app::ui {
    class UIOptionToggleData : public hh::fnd::ReferencedObject {
    public:
        csl::ut::VariableString valueName;
        char byte28;
        int dword2C;
        int value;
        int dword34;

        inline UIOptionToggleData(csl::fnd::IAllocator* allocator) : valueName{ allocator } {}
    };

    class UIIntegerToggleData : public UIOptionToggleData {
    public:
        inline UIIntegerToggleData(csl::fnd::IAllocator* allocator) : UIOptionToggleData{ allocator } {}
    };
}
