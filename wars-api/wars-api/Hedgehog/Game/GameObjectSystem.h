#pragma once

namespace hh::game {
    class GameObjectSystem : public fnd::BaseObject, public csl::fnd::Singleton<GameObjectSystem> {
        class GOComponentReference {
            const char* name;
            GOComponentClass* componentClass;
            fnd::RflClass* reflectionClass;
        };

    public:
        csl::fnd::IAllocator* pObjectAllocator;
        fnd::ThreadSafeTlsfHeapAllocator objectAllocator;
        GameObjectRegistry* gameObjectRegistry;
        GOComponentRegistry* goComponentRegistry;

        static fnd::HandleManager* handleManager;
        GameObjectSystem(csl::fnd::IAllocator* pAllocator);

        // Fully inlined in Frontiers
        void Initialize();

        static void LoadGameObjectClasses();
    };
}
