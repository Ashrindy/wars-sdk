#pragma once

#define SCENEANIM_DECLARATION(NAME) public: \
    static hh::scene::SceneAnimation* CreateAndSetup(hh::scene::SceneAnimationDescription& desc); \
    NAME(hh::scene::SceneAnimationDescription& desc); \
    bool Setup(hh::scene::SceneAnimationDescription& desc);

namespace hh::scene {
    class SceneControl;
    class SceneObject;

    struct SceneAnimationDescription {
        csl::ut::VariableString name;
        SceneControl* sceneControl;
        csl::fnd::IAllocator* allocator;
        int resourceType;
        int stateCount;
        fnd::ManagedResource* resAnim;
        SceneObject* sceneObject;
        fnd::ManagedResource* resAnimator;
        fnd::ManagedResource* resParticleLocation;
        fnd::Packfile* scenePac;
        SceneBuilder::ResourceNameResolver* resourceNameResolver;
        int32_t unk9;
        char unk9b;
        gfx::GOCVisualModel* visualModel;
    };

    class SceneAnimation : public hh::fnd::ReferencedObject {
    public:
        int resourceType;
        float unk1sc;

        virtual void UnkFunc0() = 0;
        virtual csl::ut::VariableString* UnkFunc1() = 0;
        virtual bool UnkFunc2(const char* a2) = 0;
        virtual bool UnkFunc3(char a2) = 0;
        virtual bool UnkFunc4(float a2, int a3) = 0;
        virtual bool UnkFunc5(int64_t a2, int a3) = 0;
        virtual bool UnkFunc6(int64_t a2, int64_t a3);
        virtual int GetResourceNameCount() = 0;
        virtual bool SetSpeed(float speed) = 0;
        virtual float GetStateDuration(int stateIdx) { return 0.0f; }
        virtual void UnkFunc10() {}
        virtual void UnkFunc11() {}
        virtual void UpdateDeltaMotion() {}
        virtual int64_t UnkFunc13() { return 0; }
        virtual int64_t GetResourceNameIdx(const char* name);
        virtual csl::ut::MoveArray<csl::ut::VariableString>* GetResourceNames() { return nullptr; }
        virtual void UnkFunc16(int64_t a2, ucsl::resources::scene::v106::TimelineNode* timelineNode) {}
        virtual int64_t UnkFunc17() { return 0; }
        virtual bool UnkFunc18() { return false; }
        virtual void UnkFunc19() {}
        virtual bool GetDeltaMotion(csl::math::Transform& transform) { return false; }
        virtual void UnkFunc21() {}
    };

    static SceneAnimation* (*sceneAnimationCreateFuncs[14])(SceneAnimationDescription&);
    static SceneAnimation* CreateAndSetupSceneAnimation(SceneAnimationDescription& desc);

    class SceneAnimationBase : public SceneAnimation {
    public:
        csl::ut::VariableString name;
        int unk3sc;
        csl::ut::VariableString sceneName;
        SceneControl* sceneControl;
        csl::fnd::IAllocator* unkAllocator;
        csl::ut::MoveArray<csl::ut::VariableString> resourceNames;
        csl::ut::MoveArray<float> stateDurations;
        csl::ut::MoveArray<int64_t> unk10sc;

        SceneAnimationBase(int resourceType, csl::ut::VariableString* name, int a4, SceneControl* sceneControl, csl::fnd::IAllocator* allocator);

        virtual int GetResourceNameCount() override;
        virtual float GetStateDuration(int stateIdx) override;
        virtual int64_t GetResourceNameIdx(const char* name) override;
        virtual csl::ut::MoveArray<csl::ut::VariableString>* GetResourceNames() override;
        virtual void UnkFunc16(int64_t a2, ucsl::resources::scene::v106::TimelineNode* timelineNode) override;
    };

    class PropertyAnimation : public SceneAnimation {
    public:
        struct Description {
            csl::ut::VariableString ununsed;
            SceneControl* sceneControl;
            csl::fnd::IAllocator* allocator;
            ControlNode* controlNode;
        };

        struct CurveEvaluator {
            ICurveEvaluator* currentEvaluator;
            HermiteCurveEvaluator hermite;
            LinearCurveEvaluator linear;
        };

        SceneControl* sceneControl;
        ControlNode* controlNode;
        ControlNode::ValueSet value;
        csl::ut::MoveArray<char> qword48;
        ucsl::resources::scene::v106::TimelineNode* timelineNode;
        float fps;
        float maybeCurrentTime;
        csl::ut::MoveArray<CurveEvaluator> curveEvaluators;
        csl::ut::MoveArray<char> qword98;

        virtual void UnkFunc0() override;
        virtual csl::ut::VariableString* UnkFunc1() override {}
        virtual bool UnkFunc2(const char* a2) override { return true; }
        virtual bool UnkFunc3(char a2) override { return true; }
        virtual bool UnkFunc4(float a2, int a3) override;
        virtual bool UnkFunc5(int64_t a2, int a3) override;
        virtual bool UnkFunc6(int64_t a2, int64_t a3) override;
        virtual int GetResourceNameCount() override { return 0; }
        virtual bool SetSpeed(float speed) override { return true; }
        virtual void UnkFunc10() override;
        virtual void UnkFunc11() override;
        virtual void UnkFunc16(int64_t a2, ucsl::resources::scene::v106::TimelineNode* timelineNode) override; // Some sort of initialize func? this is used at creation

        static PropertyAnimation* CreateAndSetup(const Description& desc);
        PropertyAnimation(const Description& description);
    };

    static fnd::ResourceTypeInfo* GetTypeInfoByType(ucsl::resources::scene::v106::SceneNode::ResourceType type);
}
