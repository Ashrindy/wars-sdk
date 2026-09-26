#pragma once

namespace gindows {
    class Control;

    class ControlCollection {
    public:
        Control* owner;
        csl::ut::MoveArray<Control*> controls;

        ControlCollection(csl::fnd::IAllocator* allocator);
    };

    class Control : public Component {
    public:
        struct Delegate { // should be csl::fnd::Delegate, but right now they don't seem to match up with what's in the sdk
            int64_t vftable;
            int64_t unk0;
            int64_t unk1;
        };

        Delegate qword40;
        Delegate qword58;
        Delegate qword70;
        Delegate qword88;
        Delegate onNameChanged;
        Delegate qwordB8;
        Delegate qwordD0;
        Delegate qwordE8;
        Delegate qword100;
        Delegate qword118;
        Delegate qword130;
        Delegate qword148;
        Delegate qword160;
        Delegate qword178;
        Delegate qword190;
        Delegate qword1A8;
        Delegate qword1C0;
        Delegate qword1D8;
        Delegate qword1F0;
        Delegate qword208;
        Delegate qword220;
        Delegate qword238;
        Delegate qword250;
        Delegate qword268;
        Delegate qword280;
        Delegate qword298;
        Delegate qword2B0;
        Delegate qword2C8;
        Delegate qword2E0;
        Delegate qword2F8;
        Delegate qword310;
        Delegate qword328;
        Delegate qword340;
        Delegate qword358;
        Delegate qword370;
        Delegate qword388;
        Delegate qword3A0;
        int qword3B8;
        int qword3BC;
        int64_t qword3C0;
        ControlCollection qword3C8;
        String name;
        Canvas qword438;
        char gap3D0[160];
        csl::math::Vector4 oword530;
        csl::math::Vector4 oword540;
        int64_t qword550;
        int64_t qword558;
        int64_t qword560;
        int dword568;
        int dword56C;
        int dword570;
        int dword574;
        int64_t qword578;
        int dword580;
        int dword584;
        int dword588;
        int64_t qword590;
        String qword598;
        int dword5E0;
        char byte5E4;
        int64_t qword5E8;
        csl::ut::StringMap<void*> csl__ut__stringmap_void__5F0;

        // screw the vfuncs for now

        void SetName(const char* name);

        Control();
    };
}
