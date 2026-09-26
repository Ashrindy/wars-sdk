#pragma once

// Unsure whether `SaveData` is a namespace or a class
namespace app::SaveData {
    class SaveManager : public hh::fnd::ReferencedObject, public csl::fnd::Singleton<SaveManager> {
    public:
        struct Impl {
            class UserData : public hh::fnd::ReferencedObject {
            public:
                unsigned int userId;
                short word1C;
                char byte1E;
                int dword20;
                heur::rfl::GameData gameData;
                int dword9818;

                UserData();
            };

            csl::fnd::IAllocator* qword0;
            csl::ut::MoveArray<hh::fnd::Reference<UserData>> userData;
            csl::fnd::IAllocator* qword28;
        };

        Impl* implementation;

        SaveManager();
        static SaveManager* Create();
    };

    heur::rfl::AudioSettingsData* GetAudioSettingsData();
}
