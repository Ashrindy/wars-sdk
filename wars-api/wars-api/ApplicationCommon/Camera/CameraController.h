#pragma once

namespace app_cmn::camera {
    class CameraFrame;
    class CameraController : public hh::fnd::RefByHandleObject {
    public:
        CameraParameter parameter;
        int64_t qword80; // maybe still camera frame
        int64_t qword88;
        char dword90;

        CameraController();

        virtual const char* GetName() const = 0;
        virtual bool UnkFunc1() { return false; }
        virtual bool UnkFunc2() { return false; }
        virtual void UnkFunc3() {}
        virtual void UnkFunc4() {}
        virtual void UnkFunc5() {}
        virtual void UnkFunc6() {}

        void SetCameraFrame(CameraFrame* cameraFrame);
    };
}
