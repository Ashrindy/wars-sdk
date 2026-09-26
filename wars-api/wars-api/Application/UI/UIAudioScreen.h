#pragma once

namespace app::ui {
    class UIAudioScreenEntry : public hh::fnd::ReferencedObject {
    public:
        csl::ut::VariableString name;
        csl::ut::MoveArray<hh::fnd::Reference<UIOptionToggleData>> options;
        int entryIndex;
        int64_t qword50;
        int64_t qword58;
        int dword60;
        int dword64;
        int value;
    };

    class UIAudioScreen : public hh::game::GameObject {
    public:
        char gap1C0[8];
        hh::fnd::Reference<hh::ui::GOCSprite> gocSprite;
        hh::ui::LayerController* mainLayoutLC;
        int64_t unkUiComponent;
        int64_t qword1E0;
        int64_t qword1E8;
        int64_t buttonGuide;
        int64_t qword1F8;
        int64_t qword200;
        bool shouldRenderPriorityBe27;
        int dword20C;
        hh::game::GameService* modeSwitchManager;
        char byte218;
        int64_t qword220;
        int64_t qword228;
        int64_t qword230;
        int64_t qword238;
        int64_t qword240;
        char byte248;
        int dword24C;
        char byte250;
        csl::ut::MoveArray<hh::fnd::Reference<UIAudioScreenEntry>> entries;

        virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual bool fUnk3() override;

        GAMEOBJECT_CLASS_DECLARATION(UIAudioScreen);
    };
}
