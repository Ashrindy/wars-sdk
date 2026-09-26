#pragma once

namespace gindows{
    class Object : public csl::ut::NonCopyable {
    public:
        volatile int refCount;

        virtual void* GetRuntimeTypeInfo() const;
        virtual ~Object() = default;

        static void* operator new(unsigned long long size);
        void Release();

        Object();
    };

    static csl::fnd::IAllocator* memoryAllocator;
    static csl::fnd::IAllocator* GetMemoryAllocator();

    struct KeyEventArgs {};
    struct MouseEventArgs {};
}
