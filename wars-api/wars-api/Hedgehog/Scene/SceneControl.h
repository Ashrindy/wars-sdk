#pragma once
#include <ucsl/resources/scene/v106.h>

namespace hh::scene{
    class SceneManager;

    class SceneListenerBase {};
    class SceneControlListener : public SceneListenerBase {
    public:
        virtual int64_t SCL_UnkFunc0(int64_t a2) = 0;
        virtual int64_t SCL_UnkFunc1(int64_t a2) = 0;
        virtual int64_t SCL_UnkFunc2(int64_t a2, const char* a3, int a4) = 0;
        virtual void SCL_UnkFunc3() = 0;
        virtual bool SCL_UnkFunc4() = 0;
        virtual void SCL_UnkFunc5() = 0;
    };

    struct ControlNode;

    class SceneControl : public hh::fnd::ReferencedObject, public hh::game::GameManagerListener, public SceneNodeBuilder {
    public:
        struct Resource {
            SceneNode* node;
            int resourceType;
            fnd::Reference<SceneAnimation> animation;
        };

        struct CameraParameters {
            csl::math::Vector3 position;
            csl::math::Vector3 unk1;
            csl::math::Vector4 unk2;
            float twist;
            float fov;
            float aspectRatio;
            float nearClip;
            float farClip;
            bool isTarget;

            CameraParameters();
        };

        struct TrackNode {
            int index;
            float frameStart;
            float frameEnd;
            bool noCurveDataAndActiveTillEnd;
            float currentTime;
            float unk5;
        };

        struct TimelineNode {
            ucsl::resources::scene::v106::TimelineNode* nodeInfo;
            TrackNode* trackNodes;
            SceneAnimation* animation;
            int resourceNameIdx;
        };

        struct PlayInfo {
            SceneControl* sceneControl;
            float currentSecond;
            float frameLength;
            float lengthInSeconds;
            float speed;
            float unk1; //end?
            float fps;
            bool isCameraChange;
            char unk2;
            csl::fnd::IAllocator* allocator;
            csl::ut::MoveArray<TimelineNode> timelineNodes;
            csl::ut::MoveArray<TrackNode> trackNodes;
            CameraParameters* currentCamParams0;
            CameraParameters* currentCamParams1;
            csl::math::Transform transform0;
            csl::math::Transform transform1;
            csl::ut::MoveArray<ControlNode>* controlNodes;
            csl::ut::MoveArray<SceneAnimation*> animations;

            PlayInfo(SceneControl* sceneControl, csl::fnd::IAllocator* allocator);
            void SetPlaybackSpeed(float speed);
            void Skip(float time);
            void ResetTime();
        };

        struct Camera {
            const char* filename;
            const char* cameraName;
            float start;
            float end;
        };

        SceneManager* sceneMgr;
        csl::ut::MoveArray<SceneControlListener*> listeners;
        csl::ut::VariableString sceneName;
        int unk0;
        float unk1;
        csl::ut::MoveArray<ObjectInfoImpl> objects;
        csl::ut::MoveArray<Resource> resources;
        CameraParameters camParams;
        CameraParameters* currentCamParams;
        CameraParameters defaultCamParams;
        CameraParameters* unk6;
        csl::math::Transform* currentSceneTransform;
        csl::math::Transform sceneTransform;
        fnd::Reference<ResScene> resource;
        fnd::Reference<ResScene> resourceEdit; // ResSceneEdit i think
        SceneBuilder::ResourceNameResolver* resourceNameResolver;
        fnd::Packfile* scenePac;
        csl::ut::MoveArray<ControlNode> controlNodes;
        csl::ut::MoveArray<fnd::Handle<SceneObject>> sceneObjects;
        bool gameManagerListenerRegistered;
        char unk12;
        char unk13;
        char unk14;
        csl::ut::MoveArray<int64_t> unk15;
        SceneNodeBuilder* nodeBuilder;
        csl::ut::StringMap<int64_t> unk16;
        csl::ut::StringMap<int64_t> unk17;
        csl::ut::PointerMap<fnd::ResourceTypeInfo*, int> resourceEnumByTypeInfo;
        SceneBuilder::ResourceNameResolver resourceNameResolvers[11];
        PlayInfo playInfo;
        csl::ut::MoveArray<Camera> cameras;
        bool unk19;
        int unk20;
        float fps;
        int unk22;
        float deltaTime;
        char unk23;

		virtual void GameObjectAddedCallback(game::GameManager* gameManager, game::GameObject* gameObject) override;

        virtual int64_t SNB_UnkFunc0(SceneNode* a2) override;
        virtual int64_t SNB_UnkFunc1(SceneControl* sceneControl, const char* nodeName) override;
        virtual int64_t SNB_UnkFunc2(int64_t a2) override;
        virtual int64_t SNB_UnkFunc3(SceneNode* a2) override;
        virtual int64_t SNB_UnkFunc4(int64_t a2, int a3, int a4) override;
        virtual int64_t SNB_UnkFunc5(int64_t a2, int64_t a3) override;
        virtual int64_t SNB_UnkFunc6(int64_t a2, int a3) override;

        SceneControl(csl::fnd::IAllocator* allocator, const char* sceneName);

        Camera* GetCamera(unsigned int idx);
        void AddAnimation(SceneAnimation* anim, SceneNode* node, int resourceType);
        ObjectInfoImpl* GetObjectInfoImpl(ucsl::resources::scene::v106::SceneNode::ResourceType resType, const char* name) const;
        ResScene* GetResource() const;
        void SetPlaybackSpeed(float speed);
        void SetScenePac(fnd::Packfile* scenePac);
        void SetTransform(const csl::math::Transform& transform);
        ControlNode* GetControlNode(const char* nodeName, const char* parameterName) const;
        int GetControlNodeIndex(const char* nodeName, const char* parameterName) const;
        void ParseControlNodes(ucsl::resources::scene::v106::SceneData* sceneData);
        void FireUpdateControlNodesCallback();
    };

    static bool IsResourceModel(ucsl::resources::scene::v106::SceneNode::ResourceType res);
    static ucsl::resources::scene::v106::SceneNode* GetSceneNode(ucsl::resources::scene::v106::SceneData* sceneData, const char* name, ucsl::resources::scene::v106::SceneNode::ResourceType resourceType);
    static void GetSceneNodeTransform(ucsl::resources::scene::v106::SceneData* sceneData, csl::math::Transform& transform, unsigned int nodeIdx);
}
