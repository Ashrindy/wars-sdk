#pragma once

namespace hh::scene {
    class SceneControl;

    class SceneBuilder {
    public:
        csl::ut::StringMap<int>* resourceEnumByName;

        class ResourceNameResolver : public hh::fnd::ResourceNameResolver {
        public:
            csl::fnd::IAllocator* allocator;
            csl::ut::StringMap<int64_t> unk1;
            csl::ut::MoveArray<int64_t> unk2;

            virtual const char* RNR_UnkFunc1(const char* name) override;
            ResourceNameResolver();
        };

        struct CreateDescription {
            const char* name;
            const char* modelResourceName;
            int index;
            int unk1;
            const char* skelResourceName;
            bool unk3;
            bool unk4;
            bool unk5;
            bool unk6;
            bool unk7;
            int unk8;
            bool unk9;
            bool unk10;
            char unk11;
        };

        virtual ~SceneBuilder();
        virtual fnd::ManagedResource* GetResource(const char* name, const fnd::ResourceTypeInfo* typeInfo) = 0;
        virtual bool GetUnk(SceneControl* sceneControl, fnd::ResourceTypeInfo* resourceType, const char* resourceName) { return true; }
        virtual bool CreateNull(SceneControl* sceneControl, const CreateDescription& desc);
        virtual bool CreateExternal(SceneControl* sceneControl, const CreateDescription& desc);
        virtual bool CreateModel(SceneControl* sceneControl, const CreateDescription& desc);
        virtual bool CreateTerrainModel(SceneControl* sceneControl, const CreateDescription& desc);
        virtual bool CreateTerrainInstanceInfo(SceneControl* sceneControl, const CreateDescription& desc) { return false; }
        virtual bool CreateEffect(SceneControl* sceneControl, const CreateDescription& desc);
    };
}
