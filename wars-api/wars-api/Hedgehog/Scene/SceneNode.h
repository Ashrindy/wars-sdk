#pragma once

namespace hh::scene{
    class SceneAnimationBase;

    class SceneNode : public hh::fnd::ReferencedObject {
    public:
        fnd::Reference<SceneObject> sceneObject;
        csl::ut::VariableString name;
        int objectIndex;
        int resourceType;
        bool isDead;

        virtual void Destroy();
        virtual void SetTransform(const csl::math::Transform& transform) {}
        virtual SceneAnimationBase* GetAnimation(unsigned int index) { return nullptr; }
        virtual bool HasAnimations() { return false; }
        virtual hh::fnd::HFrame* GetHFrame();

        SceneNode(SceneObject* sceneObject, csl::ut::VariableString& name, int resourceType, bool isDead);
    };

    class NullSceneNode : public SceneNode {
    public:
        virtual void Destroy() override;
        virtual void SetTransform(const csl::math::Transform& transform) override;

        NullSceneNode(SceneObject* sceneObject, csl::ut::VariableString& name);
    };

    class EffectSceneNode : public SceneNode {
    public:
        csl::math::Vector3 scale;
        csl::ut::VariableString qword50;
        csl::math::Transform transform;
        char byte90;
        char byte91;
        char byte92;
        const char* qword98;
        float dwordA0;
        int dwordA4;
        int dwordA8;
        fnd::WorldPosition owordB0;
        int64_t qwordD0;
        char byteD8;
        int64_t qwordC0;
        char byteC8;

        virtual void Destroy() override;
        virtual void SetTransform(const csl::math::Transform& transform) override;

        EffectSceneNode(SceneObject* sceneObject, csl::ut::VariableString& name, csl::ut::VariableString& unk, const csl::math::Transform& transform);
    };

    class ModelSceneNode : public SceneNode {
    public:
        SceneAnimationBase* animationsByResources[16];
        int animCount;
    
        virtual void Destroy() override;
        virtual void SetTransform(const csl::math::Transform& transform) override;
        virtual SceneAnimationBase* GetAnimation(unsigned int index) override;
        virtual bool HasAnimations() override;
        virtual hh::fnd::HFrame* GetHFrame() override;

        ModelSceneNode(SceneObject* sceneObject, csl::ut::VariableString& name, bool isDead);
        void AddVisualAnimation(SceneAnimationBase* anim);
    };

    class TerrainSceneNode : public SceneNode {
    public:
        gfx::GOCVisualModel* qword40;

        virtual void Destroy() override {}
        virtual void SetTransform(const csl::math::Transform& transform) override;
        virtual hh::fnd::HFrame* GetHFrame() override;

        TerrainSceneNode(SceneObject* sceneObject, gfx::GOCVisualModel* qword40, csl::ut::VariableString& name);
    };

    class LightSceneNode : public SceneNode {
    public:
        fnd::HFrame* lightFrame;

        virtual void SetTransform(const csl::math::Transform& transform) override;
    };
}
