#pragma once

namespace hh::game {
	class CameraManagerListener {
	public:
		virtual ~CameraManagerListener();
	};

	class InternalCameraStack : public fnd::ReferencedObject {
	public:
		int id;
		csl::ut::MoveArray<CameraComponent*> components;
		InternalCameraStack(csl::fnd::IAllocator* allocator);
	};

	class CameraManager : public GameService {
		csl::ut::MoveArray<CameraComponent*> components;
		csl::ut::MoveArray<InternalCameraStack*> cameraStacks;
		csl::ut::InplaceMoveArray<CameraManagerListener*, 1> listeners;
		bool cameraStackEnabledFlags;

	public:
		void AddComponent(CameraComponent* component);
		void RemoveComponent(CameraComponent* component);

		CameraComponent* GetTopComponent(int viewportId);
		inline void GetComponents(int viewportId, csl::ut::MoveArray<CameraComponent*>& components) {
			auto* stack = cameraStacks[viewportId];
			components.reserve(stack->components.size());
			
			for (auto* component : stack->components)
				components.push_back(component);
		}
		void AddComponentToStack(CameraComponent* component);
		void RemoveComponentFromStack(CameraComponent* component);

		void SetComponentLookAtPos(CameraComponent* component, const csl::math::Vector3& lookAtPos);
		void SetComponentViewMatrix(CameraComponent* component, const csl::math::Matrix44& viewMatrix);
		void SetComponentPerspectiveProjectionMatrix(CameraComponent* component, float fov, float aspectRatio, float nearClip, float farClip);
		void SetComponentPerspectiveProjectionMatrix(CameraComponent* component, float top, float bottom, float left, float right, float nearClip, float farClip);
		void SetComponentOrthogonalProjectionMatrix(CameraComponent* component, float top, float bottom, float left, float right, float nearClip, float farClip);

		void AddListener(CameraManagerListener* listener);
		void RemoveListener(CameraManagerListener* listener);

		inline size_t GetCameraCount() {
			return cameraStacks.size();
		}

		inline csl::ut::MoveArray<CameraComponent*>& GetComponents() {
			return components;
		}

		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		
		GAMESERVICE_CLASS_DECLARATION(CameraManager)
	};
}
