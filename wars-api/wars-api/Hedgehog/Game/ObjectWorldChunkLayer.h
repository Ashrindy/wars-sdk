#pragma once

namespace hh::game {
    class ObjectWorldChunkLayer : public fnd::ReferencedObject {
        enum class Flag : uint8_t {
            ENABLED,
        };

        csl::ut::Bitset<Flag> flags;
        ObjectWorldChunk* chunk;
        ResObjectWorld* resource;
    public:
        ObjectWorldChunkLayer(ResObjectWorld* resource);
        static inline ObjectWorldChunkLayer* Create(csl::fnd::IAllocator* allocator, ResObjectWorld* resource) {
            return new (allocator) ObjectWorldChunkLayer(resource);
        }
        void SetObjectWorldChunk(ObjectWorldChunk* chunk);
        const char* GetName() const;
        inline ResObjectWorld* GetResource() {
            return resource;
        }
        void SetEnable(bool enabled);
        bool IsEnable() const;

        inline void AddObjectData(ObjectData* objData, bool enabled) {
            if (chunk)
                chunk->AddWorldObjectStatus(objData, enabled);
            if (resource)
                resource->AddObject(objData);
        }

        inline void RemoveObjectData(ObjectData* objData);
    };
}
