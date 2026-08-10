#pragma once

namespace app::scene {
    class GOCScene : public hh::game::GOComponent, public hh::game::GameStepListener, public hh::scene::SceneControlListener {
    public:
        void* gocSceneListener;
        int dword88;
        int dword8C;
        hh::scene::ResScene* resource;
        hh::fnd::Reference<hh::fnd::Packfile> packfile;
        int64_t qwordA0;
        hh::fnd::Reference<hh::fnd::Packfile> packfile1;
        csl::math::Vector3 position;
        csl::math::Quaternion rotation;
        csl::math::Vector3 scale;
        hh::scene::SceneControl* sceneControl;
        void* sceneCamera;
        hh::fnd::Reference<hh::game::InputComponent> inputComp; // for skipping
        hh::fnd::Handle<hh::game::GameObject> uiLockOnCursor;
        short flags;
        char byteFE;

        GOCScene();

        virtual const char* GetCategory() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual bool ProcessMessage(hh::fnd::Message& msg) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

		virtual void PreStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        virtual int64_t SCL_UnkFunc0(int64_t a2) override;
        virtual int64_t SCL_UnkFunc1(int64_t a2) override;
        virtual int64_t SCL_UnkFunc2(int64_t a2, const char* a3, int a4) override;
        virtual void SCL_UnkFunc3() override {}
        virtual bool SCL_UnkFunc4() override { return false; }
        virtual void SCL_UnkFunc5() override {}
        
        GOCOMPONENT_CLASS_DECLARATION_INLINE_GETCLASS(GOCScene);
    };
}
