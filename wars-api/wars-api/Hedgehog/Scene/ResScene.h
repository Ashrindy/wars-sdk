#pragma once

namespace hh::scene{
    class ResScene : public hh::fnd::ManagedResource{
    public:
        csl::ut::MoveArray<fnd::Reference<fnd::ManagedResource>> relatedResources;
        bool resolved;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Resolve(hh::fnd::ResourceResolver& resolver) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResScene)
    };
}
