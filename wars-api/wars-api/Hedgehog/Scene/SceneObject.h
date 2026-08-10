#pragma once

namespace hh::scene {
    class SceneNode;
    class SceneControl;
    class SceneNodeBuilder;

    class SceneObject : public game::GameObject {
    public:
        struct BaseDescription {
            SceneNode* sceneNode;
            int objectLayer;
        };

        fnd::Reference<SceneNode> sceneNode;
        bool registerInSceneControl;
    };

    class NullSceneNode;

    class NullSceneObject : public SceneObject {
    public:
        struct Description : public BaseDescription {
            fnd::WorldPosition* worldPos;
            SceneNodeBuilder* nodeBuilder;
            const char* name;
        };

        Description desc;

		virtual void AddCallback(game::GameManager* gameManager) override;

        bool Setup(const Description& desc);
        
        GAMEOBJECT_CLASS_DECLARATION(NullSceneObject);
    };

    class ModelSceneObject : public SceneObject {
    public:
        struct Description : public BaseDescription {
            gfx::ResModel* modelRes;
            int64_t qword1E8;
            fnd::ManagedResource* skelRes;
            fnd::WorldPosition* worldPos;
            SceneNodeBuilder* nodeBuilder;
            const char* name;
            SceneControl* sceneControl;
            int dword218;
            bool invisible;
            int dword220;
            char byte224;
        };

        Description desc;
        int gocVisualCount;

        virtual void AddCallback(game::GameManager* gameManager) override;
		virtual void UnkFunc9(void* a2, fnd::UpdatingPhase phase) override;

        bool Setup(const Description& desc);
        void SetTransform(const csl::math::Transform& transform, int64_t unused, csl::fnd::IAllocator* tempAllocator, int gocVisualCount);

        GAMEOBJECT_CLASS_DECLARATION(ModelSceneObject);
    };

    class EffectSceneObject : public SceneObject {
    public:
        struct Description : public BaseDescription {
        };

        Description desc;

        virtual void AddCallback(game::GameManager* gameManager) override;

        bool Setup(const Description& desc);

        GAMEOBJECT_CLASS_DECLARATION(EffectSceneObject);
    };
}
