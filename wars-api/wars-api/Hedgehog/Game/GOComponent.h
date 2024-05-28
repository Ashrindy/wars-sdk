#pragma once

#define GOCOMPONENT_CLASS_DECLARATION(ClassName) private:\
		static const hh::game::GOComponentClass componentClass;\
		static ClassName* Create(csl::fnd::IAllocator* allocator);\
	public:\
		static const hh::game::GOComponentClass* GetClass();

#define GOCOMPONENT_CLASS_DECLARATION_INLINE_GETCLASS(ClassName) private:\
		static const hh::game::GOComponentClass componentClass;\
		static ClassName* Create(csl::fnd::IAllocator* allocator);\
	public:\
		inline static const hh::game::GOComponentClass* GetClass() {\
			return &RESOLVE_STATIC_VARIABLE(componentClass);\
		}

namespace hh::game
{
	class GOComponent;
	class GameObject;
	class GOComponentClass
	{
	public:
		const char* pName;
		GOComponentClass* parent{};
		const char* category;
		size_t size;
        GOComponent* (*instantiator)(csl::fnd::IAllocator* pAllocator);
		uint32_t alignmentMaybe;
		void* unk2;

		GOComponentClass(const char* name, GOComponentClass* parent, const char* category, size_t size, GOComponent* (*instantiator)(csl::fnd::IAllocator* pAllocator), uint32_t alignmentMaybe, void* unk2);
	};
	
	class GOComponent : public fnd::RefByHandleObject
	{
	public:
		enum class GOCEventMask : uint16_t {
			ADDED_TO_OBJECT = 0,
			ADDED_TO_OBJECT_2 = 1,
			REMOVED_FROM_OBJECT = 2,
			UPDATE_SET_EDITOR = 9,
			OTHER_COMPONENT_ADDED_OR_REMOVED = 13,
			RESOURCE_RELOADS = 14,
		};

		enum class GOCEvent {
			ADDED_TO_OBJECT,
			REMOVED_FROM_OBJECT,
			UPDATE_SET_EDITOR,
			UNK3,
			COMPONENT_ADDED,
			COMPONENT_REMOVED,
			OBJECT_LAYER_CHANGED,
			PRE_RESOURCE_RELOAD, // Sent to all GameObjects' GOCs when GameManager's ReloaderListener::PreResourceReloadCallback is called
			POST_RESOURCE_RELOAD, // Sent to all GameObjects' GOCs when GameManager's ReloaderListener::PostResourceReloadCallback is called
		};

		struct Unk1 {
			int64_t unk39;
			int64_t unk40;
		};

		GameObject* owner{};
		csl::ut::Bitset<GOCEventMask> gocEventMask;
		uint16_t index; // index in GameObject's list
		csl::ut::Bitset<fnd::UpdatingPhase, uint8_t> updateFlags;
		uint8_t updatePriorityByPhase[3];
		uint32_t nameHash;
		uint32_t messageMask;
		GOComponentClass* pStaticClass{};
		Unk1 unknown43[3];

		GOComponent();
		virtual ~GOComponent();

		virtual void* GetRuntimeTypeInfo();
		virtual const char* GetCategory();
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) {}
		virtual bool ProcessMessage(fnd::Message& msg) { return false; }

		/*
		 * data contains data dependent on the event:
		 * Event                      | Data
		 * OBJECT_LAYER_CHANGED       | previous layer id
		 * UNKNOWN_THING_RELOADED     | the unknown thing that was reloaded
		 * RESOURCE_RELOADED          | the ManagedResource that was reloaded
		 */
		virtual void OnGOCEvent(GOCEvent event, GameObject& ownerGameObject, void* data) {}

		void AddedToObject(GameObject* gameObject);
		void RemovedFromObject(GameObject* gameObject);

		static GOComponent* Create(GameObject& ownerGameObject, const GOComponentClass& componentClass);

		inline GameObject* GetOwnerGameObject() {
			return owner;
		}

		GOComponent* GetComponentByClass(const GOComponentClass& componentClass) const;

		template<typename T>
		GOComponent* GetComponent() const {
			return GetComponentByClass(T::GetClass());
		}

		void SetNameHash(const char* name);
		void SetOwner(GameObject* owner);
		void SetUpdateFlag(hh::fnd::UpdatingPhase updatingPhase, bool enabled);
		void SetUpdatePriority(hh::fnd::UpdatingPhase updatingPhase, uint8_t priority);
		fnd::Message* SendMessageToGameObject(const fnd::Handle<GameObject>& handle, fnd::Message& message);
		bool SendMessageImmToGameObject(const fnd::Handle<GameObject>& handle, fnd::Message& message);
	};
}
