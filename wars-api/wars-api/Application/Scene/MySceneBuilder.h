#pragma once

namespace app::scene {
    class MySceneBuilder : public hh::scene::SceneBuilder {
    public:
        hh::fnd::Packfile* scenePac;

        virtual hh::fnd::ManagedResource* GetResource(const char* name, const hh::fnd::ResourceTypeInfo* typeInfo) override;
        virtual bool GetUnk(hh::scene::SceneControl* sceneControl, hh::fnd::ResourceTypeInfo* resourceType, const char* resourceName) override;
    };
}
