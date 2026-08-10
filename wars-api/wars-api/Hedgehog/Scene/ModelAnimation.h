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
        float currentTime;
        float speed;
        float unk5;
        int unk5b;
        csl::math::Transform unk6;
        csl::math::Transform deltaMotion;
        game::GOComponent* gocEffect; //eff::GOCEffect
        int64_t unk13;
        int32_t unk14;
        int32_t unk14b;
        int32_t unk15;
        bool deltaMotionUpdated;

        SCENEANIM_DECLARATION(SkeletalModelAnimationAnimator);

        virtual void UnkFunc0() override;
        virtual csl::ut::VariableString* UnkFunc1() override;
        virtual bool UnkFunc2(const char* a2) override;
        virtual bool UnkFunc3(char a2) override;
        virtual bool UnkFunc4(float a2, int a3) override;
        virtual bool UnkFunc5(int64_t a2, int a3) override;
        virtual bool SetSpeed(float speed) override;
        virtual void UnkFunc11() override;
        virtual void UpdateDeltaMotion() override;
        virtual void UnkFunc19() override;
        virtual bool GetDeltaMotion(csl::math::Transform& transform) override;
    };
}
