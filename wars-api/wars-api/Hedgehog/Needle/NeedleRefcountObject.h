#pragma once

namespace hh::needle {
    struct SRefCountAddReleaseNeedleObject;
    // class NeedleRefcountObject : public NeedleObject, public rsdx::rsdx_noncopyable {
    class NeedleRefcountObject : public NeedleObject {
        friend struct SRefCountAddReleaseNeedleObject;
        uint32_t pad;
        uint32_t refCount;
    protected:
        virtual void ReleasePostDestroyInternal();
        virtual void GetDependRefcountObject();
        virtual ~NeedleRefcountObject();
        void AddRef();
        void Release();
    };
}
