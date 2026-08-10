#pragma once
#include <ucsl/resources/scene/v106.h>

namespace hh::scene {
    class ObjectInfo {
    public:
        SceneNode* node;
        int64_t unk0;
        fnd::Reference<fnd::HFrame> currentFrame;
        fnd::Reference<fnd::HFrame> previousFrame;
        unsigned int objectIndex;
        unsigned char resourceType;
    };

    class ObjectInfoImpl : public ObjectInfo {
    public:
        virtual SceneNode* GetNode();
        virtual csl::math::Transform GetTransform(ucsl::resources::scene::v106::SceneData* sceneData);
        virtual int64_t UnkFunc1(int64_t a2, int64_t a3);
        virtual void SetIndex(unsigned int index);
        virtual unsigned int GetIndex();
        virtual ~ObjectInfoImpl();
    };
}
