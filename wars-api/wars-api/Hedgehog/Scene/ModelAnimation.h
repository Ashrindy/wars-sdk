#pragma once

namespace hh::scene{
    class ModelAnimation : public SceneAnimationBase {
    public:
    };

    class SkeletalModelAnimationAnimator : public ModelAnimation {
    public:
        SceneObject* modelSceneObject;
        fnd::ManagedResource* resAnimator; //anim::ResAnimator
        game::GOComponent* gocAnimator; //anim::GOCAnimator
        float curTime;
        float unk4;
        float unk5;
        csl::math::Transform unk6;
        csl::math::Transform unk9;
        game::GOComponent* gocEffect; //eff::GOCEffect
        int64_t unk13;
        int32_t unk14;
        int32_t unk14b;
        int32_t unk15;
        char unk16;

        SCENEANIM_DECLARATION(SkeletalModelAnimationAnimator);

        virtual void UnkFunc0() override;
        virtual csl::ut::VariableString* UnkFunc1() override;
        virtual bool UnkFunc2(const char* a2) override;
        virtual bool UnkFunc3(char a2) override;
        virtual bool UnkFunc4(float a2, int a3) override;
        virtual bool UnkFunc5() override;
        virtual bool UnkFunc8(float a2) override;
        virtual void UnkFunc11() override;
        virtual void UnkFunc12() override;
        virtual void UnkFunc19() override;
        virtual bool UnkFunc20() override;
    };
}
