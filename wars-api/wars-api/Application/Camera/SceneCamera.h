#pragma once

namespace app::camera {
    class SceneCamera : public app_cmn::camera::CameraController {
    public:
        hh::fnd::Reference<hh::scene::SceneControl> sceneControl;
        int sceneCameraNear;
        int sceneCameraFar;

        virtual const char* GetName() const override;
        virtual void UnkFunc3() override;
        virtual void UnkFunc4() override;
    };
}
