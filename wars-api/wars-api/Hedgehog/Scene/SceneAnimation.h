#pragma once

#define SCENEANIM_DECLARATION(NAME) public: \
    static hh::scene::SceneAnimation* CreateAndSetup(hh::scene::SceneAnimationDescription& desc); \
    NAME(hh::scene::SceneAnimationDescription& desc); \
    bool Setup(hh::scene::SceneAnimationDescription& desc);

namespace hh::scene{
    class SceneControl;
    class SceneObject;

    struct SceneAnimationDescription {
        csl::ut::VariableString name;
        SceneControl* sceneControl;
        csl::fnd::IAllocator* allocator;
        int resourceType;
        int unk2;
        int64_t unk3;
        SceneObject* sceneObject;
        int64_t unk5;
        int64_t unk6;
        fnd::Packfile* scenePac;
        SceneBuilder::ResourceNameResolver* resourceNameResolver;
        int32_t unk9;
        char unk9b;
        gfx::GOCVisualModel* visualModel;
    };

    class SceneAnimation : public hh::fnd::ReferencedObject{
    public:
        virtual void UnkFunc0() = 0;
        virtual csl::ut::VariableString* UnkFunc1() = 0;
        virtual bool UnkFunc2(const char* a2) = 0;
        virtual bool UnkFunc3(char a2) = 0;
        virtual bool UnkFunc4(float a2, int a3) = 0;
        virtual bool UnkFunc5() = 0;
        virtual int64_t UnkFunc6();
        virtual int GetResourceNameCount() = 0;
        virtual bool UnkFunc8(float a2) = 0;
        virtual float UnkFunc9(int a2) { return 0.0f; }
        virtual void UnkFunc10() {}
        virtual void UnkFunc11() {}
        virtual void UnkFunc12() {}
        virtual int64_t UnkFunc13() { return 0; }
        virtual int64_t GetResourceNameIdx(const char* name);
        virtual csl::ut::MoveArray<csl::ut::VariableString>& GetResourceNames();
        virtual void UnkFunc16() {}
        virtual int64_t UnkFunc17() { return 0; }
        virtual bool UnkFunc18() { return false; }
        virtual void UnkFunc19() {}
        virtual bool UnkFunc20() { return false; }
        virtual void UnkFunc21() {}
    };

    static SceneAnimation* (*sceneAnimationCreateFuncs[14])(SceneAnimationDescription&);
    static SceneAnimation* CreateAndSetupSceneAnimation(SceneAnimationDescription& desc);

    class SceneAnimationBase : public SceneAnimation {
    public:
        int resourceType;
        float unk1sc;
        csl::ut::VariableString name;
        int unk3sc;
        csl::ut::VariableString sceneName;
        SceneControl* sceneControl;
        csl::fnd::IAllocator* unkAllocator;
        csl::ut::MoveArray<csl::ut::VariableString> resourceNames;
        csl::ut::MoveArray<int64_t> unk9sc;
        csl::ut::MoveArray<int64_t> unk10sc;

        SceneAnimationBase(int resourceType, csl::ut::VariableString* name, int a4, SceneControl* sceneControl, csl::fnd::IAllocator* allocator);

        virtual int GetResourceNameCount() override;
        virtual float UnkFunc9(int a2) override;
        virtual int64_t GetResourceNameIdx(const char* name) override;
        virtual csl::ut::MoveArray<csl::ut::VariableString>& GetResourceNames() override;
        virtual void UnkFunc16() override;
    };
}
