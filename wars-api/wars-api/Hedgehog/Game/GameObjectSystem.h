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

        GameObjectSystem(csl::fnd::IAllocator* pAllocator);

        // Fully inlined in Frontiers
        void Initialize();

        static void LoadGameObjectClasses();

        static GameObject* GetGameObjectByHandle(const fnd::Handle<hh::game::GameObject>& handle);
        inline static GOComponent* GetComponentByHandle(const fnd::Handle<hh::game::GOComponent>& handle) {
            return *handle;
        }

        template<typename T>
        inline static T* GetGameObjectByHandle(const fnd::Handle<T, fnd::HandleManager<hh::game::GameObject>>& handle) {
            return static_cast<T*>(GetGameObjectByHandle(reinterpret_cast<const fnd::Handle<hh::game::GameObject>&>(handle)));
        }

        template<typename T>
        inline static T* GetComponentByHandle(const fnd::Handle<T, fnd::HandleManager<hh::game::GOComponent>>& handle) {
            return static_cast<T*>(GetComponentByHandle(reinterpret_cast<const fnd::Handle<hh::game::GOComponent>&>(handle)));
        }
    };
}

template class hh::fnd::HandleManager<hh::game::GameObject>;
template class hh::fnd::HandleManager<hh::game::GOComponent>;
template class hh::fnd::Handle<hh::game::GameObject>;
template class hh::fnd::Handle<hh::game::GOComponent>;
