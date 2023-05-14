#pragma once
#include <memory>
#include <vector>
#include <glm/glm.hpp>
#include "Scene.h"

namespace dae
{
	class Component;
	class Texture2D;

	// todo: this should become final.
	class GameObject final
	{
	public:
		void Update(float deltaTime);
		void FixedUpdate(float fixedTime);
		void Render() const;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		GameObject();
		~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		template <typename T>
		T* GetComponent()
		{
			for (auto& component : m_pVectorComponents)
			{
				T* ptr =  dynamic_cast<T*>(component.get()); //
				if (ptr)
				{
					return ptr;
				}
			}
			return nullptr;
		}

		template <typename T, typename... Args>
		T& AddComponent(Args&&... args)
		{
			m_pVectorComponents.emplace_back(std::make_shared<T>(this, std::forward<Args>(args)...));
			return *static_cast<T*>(m_pVectorComponents.back().get());
		}

		template <typename T>
		void RemoveComponent()
		{
			for (auto i = m_pVectorComponents.begin(); i != m_pVectorComponents.end(); ++i)
			{
				if (dynamic_cast<T*>(i->get()))
				{
					m_pVectorComponents.erase(i);
					break;
				}
			}
		}
		void SetParent(GameObject* parent, bool keepWorldPosition);
		GameObject* GetParent()
		{
			return m_pParentGameObject;
		}

		bool HasParent();
		void SetPositionDirty();
		void AddChild(GameObject* childGameObj);
		void RemoveChild(GameObject* childGameObj);

	private:
		// todo: mmm, every gameobject has a texture? Is that correct?
		//Transform m_transform{};
		//std::shared_ptr<Texture2D> m_texture{};

		std::vector<std::shared_ptr<dae::Component>> m_pVectorComponents;
		
		// Parent | Children + dirty flag week 2
		std::vector<dae::GameObject*> m_pVectorChildren;
		GameObject* m_pParentGameObject;
	};
}
