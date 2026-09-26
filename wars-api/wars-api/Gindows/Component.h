#pragma once

namespace gindows{
    class Component : public Object {
    public:
        csl::ut::MoveArray<int64_t> qword10;
        int64_t qword30;
        int64_t qword38;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void OnRender() = 0;

        Component();
    };
}