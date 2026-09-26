#pragma once

namespace gindows {
    class ObjectDeleter : public Object, public csl::fnd::Singleton<ObjectDeleter> {
    public:
        int dword10;
        int dword14;
        csl::ut::MoveArray<Object*> objectsInQueue;

        virtual void* GetRuntimeTypeInfo() const;

        void Delete(Object* object);

        ObjectDeleter();
    };

    class ToolStripMenuItemTransition : public Object, public csl::fnd::Singleton<ToolStripMenuItemTransition> {
    public:
        int dword10;
        int dword14;
        int64_t qword18;
        int dword20;

        virtual void* GetRuntimeTypeInfo() const;

        ToolStripMenuItemTransition();
    };

    class ManagerImpl : public Object {
    public:
        int64_t qword10;
        int backColor;
        int foreColor;
        int dword20;
        int dword24;
        int dword28;
        int64_t qword30;
        int64_t qword38;
        csl::ut::MoveArray<int64_t> qword40;
        Screen* screen;
        Desktop* desktop;
        ToolTipManager* tooltipManager;
        ToolTip* defaultTooltip;
        int64_t qword80;
        int64_t qword88;
        char char90[0x80];
        int64_t qword110;
        csl::ut::MoveArray<int64_t> qword118;
        int64_t qword138;
        int64_t qword140;
        int64_t qword148;
        int dword150;
        int64_t qword158;
        int64_t qword160;
        int64_t qword168;

        virtual void* GetRuntimeTypeInfo() const;

        ManagerImpl();
    };

    class WindowManager : public Object {
    public:
        int dword10;
        csl::ut::LinkList<Object> csl__ut__detail__linklistimpl18;
        csl::ut::LinkList<Object> csl__ut__detail__linklistimpl38;
        int64_t qword58;
        int64_t qword60;
        int64_t qword68;
        char byte70;
        int64_t qword78;

        virtual void* GetRuntimeTypeInfo() const;

        WindowManager();
    };

    class Manager : public Object {
    public:
        ManagerImpl* impl;
        WindowManager* windowManager;
        int dword20;
        short word24;
        char byte26;

        virtual void* GetRuntimeTypeInfo() const;

        static void Initialize(unsigned int width, unsigned int height);
        static Manager* instance;
        static Manager* GetInstance();
        
        void* GetDefaultFontPointer() const;
        void* GetGraphicsPointer() const;
        int* GetDefaultBackColorPointer() const;
        int* GetDefaultForeColorPointer() const;

        Manager();
    };
}
