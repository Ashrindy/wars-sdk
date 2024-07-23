#pragma once

namespace SurfRide
{
    struct SRS_PROJECT
    {
        const char* name{};
        unsigned short sceneCount{};
        unsigned short unk1{};
        unsigned short textureListCount{};
        unsigned short fontCount{};
        SRS_SCENE* scenes{};
        SRS_TEXTURELIST* textureLists{}; // SRS_TEXTURELIST
        SRS_FONT* fonts{}; // SRS_FONT
        SRS_CAMERA camera{};
        int startFrame{};
        int endFrame{};
        float frameRate{};
        void* userData{};
    };

    class BinaryData;
    class Project : public ReferencedObject
    {
        void LoadTextureListChunk(void* data, BinaryData& binaryData);
        void LoadProjectChunk(void* data, BinaryData& binaryData, bool cloneBinaryData);
    public:
        SRS_PROJECT* projectData;
        TextureList** textureLists;
        uint32_t textureListCount;
        csl::ut::MoveArray<SurfRide::Scene*> scenes;
        BinaryData* binaryData;
        void* binaryDataData;

        Project();
        static Project* Create(const BinaryData& binaryData, bool cloneBinaryData);
        SRS_CAMERA* GetCameraData();
        Scene* GetScene(const char* name);
        void ApplyMemoryImageToTextureList(void* image, BinaryData* binaryData);
        void ApplyMemoryImageToProject(void* image, BinaryData* binaryData, bool unkParam);
    };

	struct ProjectIterator {
		SRS_PROJECT* project;

		SceneCollection GetScenes() const;
	};
}
