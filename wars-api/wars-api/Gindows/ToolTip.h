#pragma once

namespace gindows {
    class ToolTipManager;

    class ToolTip : public Component {
    public:
        class State {
        public:
            ToolTip* tooltip;
            int64_t qword10;
            float dword18;

            virtual ~State();
            virtual void OnExecute(float a2);
            virtual void OnKeyDown(KeyEventArgs& args) {}
            virtual void OnMouseEnter() {}
            virtual void OnMouseLeave() {}
            virtual void OnMouseMove(MouseEventArgs& args) {}
            virtual void OnMouseDown(MouseEventArgs& args) {}
            virtual void OnMouseUp(MouseEventArgs& args) {}
            virtual void OnMouseWheel(MouseEventArgs& args) {}
            virtual void OnNotifyTargetID(const csl::ut::Point2<int>& maybePosition, int unk0) {}
            virtual void OnRender() {}
        };

        class StateIdle : public State {
        public:
            virtual void OnMouseEnter() override;
            virtual void OnNotifyTargetID(const csl::ut::Point2<int>& maybePosition, int unk0) override;
        };

        State* currentState;
        char curStateMemory[0x100];
        csl::ut::StringMap<int64_t> csl__ut__stringmap_void__148;
        int64_t qword178;
        int dword180;
        int dword184;
        int dword188;
        bool isDefault;
        int64_t qword190;
        int64_t qword198;

        virtual void OnRender() override;

        void SetDefaultToolTip();

        ToolTip(ToolTipManager* tooltipManager);
    };

    class ToolTipManager : public Object {
    public:
        csl::ut::LinkList<ToolTip> tooltips;

        virtual void* GetRuntimeTypeInfo() const;

        void Add(ToolTip* tooltip);

        ToolTipManager();
    };
}
