#pragma once

namespace hh::anim {
    class SkeletalMeshBinding;
}

namespace hh::gfx {
    // Actually called GOCVisualMode::Description but I'm not sure how to resolve the mutual dependency with Setup.
    // Assumed, some of these fields may not be part of this but of the GOCVisualModel instead
    struct GOCVisualModelDescription : public GOCVisualTransformed::SetupInfo {
        enum class Flag {
            SCENE_EDITOR_RENDER = 0x14,
            NO_CONTROL_RENDER_OPTION = 0x15,
            RENDER_COLOR_MASK = 0x16,
            NO_SHADOW_RECEIVE = 0x17,
            NO_SHADOW_CAST = 0x18,
            NO_MATERIAL_OPTIMIZE = 0x19,
            UNK1 = 0x1A, // Assigned in GOCVisualModelImpl::Setup
            UNK2 = 0x1B,
            IS_HEIGHTMAP_REACTOR = 0x1C,
            IS_SHADOW_RECEIVE = 0x1D,
            IS_SHADOW_CASTER = 0x1E,
        };
        fnd::ManagedResource* model;
        uint64_t unk320;
        uint64_t unk321;
        fnd::ManagedResource* skeleton;
        csl::ut::Bitset<Flag> flags;
        uint32_t unk322;
        int unk323;
        int unk323b;
        int unk324;
        int unk325;
        fnd::ManagedResource* unk326;
        fnd::ManagedResource* unk327;
        bool isSky;
        bool isOccluder;
        bool disableColorDraw;
        bool useGIPRT;
        bool useGISG;
        uint32_t unk330;
        uint32_t useSkeletalAnimRelated;
        uint32_t unk331;
        char unk332;
        unsigned int name;
        unsigned int masterPoseComponentNameHash;
        char unk333;

        GOCVisualModelDescription();
    };

    class GOCVisualModel;
    class GOCVisualModelImpl {
    public:
        struct Unk1 {
            uint8_t unk1;
            uint8_t unk2;
            uint32_t unk3[64];
            uint8_t unk4;
        };

    private:
        needle::PBRModelInstance* modelInstance;
        csl::fnd::IAllocator* allocator;
        uint16_t unk2;
        int unk3;
        uint32_t unk4;
        uint64_t unk5;
        uint64_t unk6;
        uint64_t unk6b;
        uint64_t unk6c;
        uint64_t unk6d;
        uint32_t unk7;
        int unk8;
        float scale;
        Unk1 unk10;
        uint64_t unk11;
        uint64_t unkpad[67];

    public:
        GOCVisualModelImpl(csl::fnd::IAllocator* allocator);
        uint64_t OnGOCVisualEvent(GOCVisualModel* visualModel, int unkParam1, unsigned int unkParam2, void* unkParam3);
        void Setup(GOCVisualModel& model, const GOCVisualModelDescription& description);
        void GetModelSpaceAabb(csl::geom::Aabb* aabb) const;
    };

    class GOCVisualModel : public GOCVisualTransformed {
        int64_t qword170;
        int64_t qword178;
        int64_t qword180;
        int64_t qword188;
        csl::ut::InplaceMoveArray<GOCVisualModel*, 3> poseComponents;
        unsigned int masterPoseComponentNameHash;
        fnd::Reference<fnd::ManagedResource> model;
        fnd::Reference<fnd::ManagedResource> skeleton;
        int64_t qword1E0;
        int64_t qword1E8;
        int64_t qword1F0;
        int64_t qword1F8;
        int64_t qword200;
        int64_t qword208;
        int64_t qword210;
        int dword218;
        GOCVisualModelDescription description;
        int64_t qword290;
        char byte298[904];
        int64_t qword620;
        char byte628;

    public:
		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void OnGOCVisualEvent(GOCVisualEvent unkParam1, unsigned int unkParam2, void* unkParam3) override;
        void SetMasterPoseComponent(GOCVisualModel* component);
        int GetNodeIndex(const char* nodeName) const;
        void Setup(const GOCVisualModelDescription& description);

        GOCOMPONENT_CLASS_DECLARATION(GOCVisualModel)
    };
}
