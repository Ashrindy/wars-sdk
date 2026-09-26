#pragma once

namespace hh::scene{
    class SceneControl;

    class SceneNodeBuilder {
    public:
        virtual int64_t SNB_UnkFunc0(SceneNode* a2) {} // Ran in ModelSceneObject AddCallback
        virtual int64_t SNB_UnkFunc1(SceneControl* sceneControl, const char* nodeName) {}
        virtual int64_t SNB_UnkFunc2(int64_t a2) {}
        virtual int64_t SNB_UnkFunc3(SceneNode* a2) {} // Ran in ModelSceneObject AddCallback
        virtual int64_t SNB_UnkFunc4(int64_t a2, int a3, int a4) {}
        virtual int64_t SNB_UnkFunc5(int64_t a2, int64_t a3) {}
        virtual int64_t SNB_UnkFunc6(int64_t a2, int a3) {}
    };
}
