#pragma once

namespace hh::gfx {
    class RenderingEngine : public fnd::ReferencedObject {
        csl::ut::MoveArray<RenderingComponent*> components;
        bool callUnkFunc1OnNewComponents;
    public:
        RenderingEngine(csl::fnd::IAllocator* allocator);
        virtual unsigned int GetModelGatherBufferSize();
        virtual void CreateRenderingDevice(void* unkParam1) = 0;
        virtual ID3D11Device* GetNativeDevice() = 0;
        virtual uint64_t Startup() = 0;
        virtual uint64_t Shutdown() = 0;
        virtual uint64_t UnkFunc8();
    };
}
