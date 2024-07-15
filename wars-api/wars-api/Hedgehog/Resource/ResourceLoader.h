#pragma once

namespace hh::fnd {
    class ResourceLoader : public ReferencedObject, public FileInfoListener {
    public:
        class Unk2 : public BaseObject {
            class Unk1 : public ReferencedObject {
                csl::ut::MoveArray<ManagedResource*> onceAddedResources; // I don't quite get it yet -- see AddResource
                csl::ut::MoveArray<ManagedResource*> twiceAddedResources;
                csl::ut::StringMap<ManagedResource*> addedResourcesByName;
            public:
                Unk1(csl::fnd::IAllocator* allocator);
            };

            csl::ut::MoveArray<Unk1*> unk1s;
            SimpleResourceContainer* simpleResourceContainer;
        public:
            Unk2(csl::fnd::IAllocator* allocator);
            Unk1* LoadTypeInfo(const ResourceTypeInfo* typeInfo);
            const csl::ut::MoveArray<ManagedResource*>& GetResourcesByTypeInfo(const ResourceTypeInfo* typeInfo);
            void SetSimpleResourceContainer(SimpleResourceContainer* simpleResourceContainer); 
            void Clear();
        };

        struct Unk3 {
            uint64_t unk1;
            bool unk2;
            csl::ut::VariableString unk3;

            Unk3(csl::fnd::IAllocator* allocator);
        };

        Unk2 unk1;
        csl::ut::MoveArray<void*> unk2;
        csl::ut::MoveArray<void*> unk3;
        csl::ut::MoveArray<void*> unk4;
        Unk3 unk5;
        csl::fnd::IAllocator* otherAllocator;
        csl::ut::VariableString unk6;
        csl::ut::MoveArray<void*> unk7;
        uint8_t unk8;

        ResourceLoader();
        inline static ResourceLoader* Create(csl::fnd::IAllocator* allocator) {
            return new (allocator) ResourceLoader();
        }

        inline void LoadPackfile(const char* uri, uint32_t unk) {
            LoadResource(uri, hh::fnd::Packfile::GetTypeInfo(), 2, 1);
        }
        void LoadResource(const char* uri, const ResourceTypeInfo* resourceTypeInfo, int unk, uint32_t unk2);
    };
}
