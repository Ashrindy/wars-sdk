#pragma once

namespace hh::scene {
    class SceneManagerListener {
    public:
        struct AddSceneNodeCallbackInfo {
            SceneControl* sceneControl;
            const char* name;
        };

        struct AddSceneObjectCallbackInfo {
            SceneControl* sceneControl;
            const char* objectName;
            SceneObject* sceneObject;
        };

        struct CreateExternalObjectInfo {
            SceneControl* sceneControl;
            const char* objectName;
        };

        virtual void AddSceneControlCallback(SceneManager* sceneManager, const char* sceneName) {}
        virtual void SML_UnkFunc1(int64_t a2, int64_t a3) {}
        virtual void SML_UnkFunc2() {}
        virtual void AddSceneNodeCallback(const AddSceneNodeCallbackInfo& info, int unk0) {}
        virtual void SML_UnkFunc4() {}
        virtual void AddSceneObjectCallback(const AddSceneObjectCallbackInfo& info) {}
        virtual void SML_UnkFunc6(int64_t a2) {}
        virtual SceneObject* CreateExternalObject(const CreateExternalObjectInfo& info) { return nullptr; }
        virtual void SML_UnkFunc8(int64_t a2) {}
        virtual void SML_UnkFunc9(int64_t a2) {}
        virtual void SML_UnkFunc10(int64_t a2) {}
        virtual void SML_UnkFunc11(int64_t a2) {}
        virtual void SML_UnkFunc12(int64_t a2) {}
        virtual void SML_UnkFunc13(int64_t a2) {}
        virtual void SML_UnkFunc14(int64_t a2) {}
        virtual void SML_UnkFunc15() {}
    };

    class SceneManager : public hh::game::GameService, public hh::game::GameStepListener {
    public:
        struct SceneControlDescription {
            const char* sceneName;
            ResScene* sceneRes;
            SceneBuilder* sceneBuilder;
            int unk0;
            csl::math::Transform sceneTransform;
            char unk1;
            fnd::Packfile* scenePac;

            SceneControlDescription();
        };

        csl::ut::MoveArray<SceneControl*> sceneControls;
        csl::ut::MoveArray<SceneManagerListener*> listeners;

        virtual void* GetRuntimeTypeInfo() override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;

        virtual void PreStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        void AddListener(SceneManagerListener* listener);
        void RemoveListener(SceneManagerListener* listener);

        void FireAddSceneObjectCallback(const SceneManagerListener::AddSceneObjectCallbackInfo& info);
        void FireAddSceneNodeCallback(const SceneManagerListener::AddSceneNodeCallbackInfo& info, int unk0);
        SceneObject* FireCreateExternalObject(const SceneManagerListener::CreateExternalObjectInfo& info);
        SceneControl* CreateControl(const SceneControlDescription& description);

        GAMESERVICE_CLASS_DECLARATION(SceneManager)
    };
}
