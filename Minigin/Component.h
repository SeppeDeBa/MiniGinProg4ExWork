#pragma once
#include <iostream>
#include "GameObject.h"


namespace dae
{
	class GameObject;
	class Component
	{
	public:

		explicit Component(GameObject* pOwner) : m_pOwner(pOwner) {};
		virtual ~Component() { m_pOwner = nullptr;};
		Component(const Component& other) = delete;
		Component(Component&& other) = delete;
		virtual void Render() const {};
		virtual void Update([[maybe_unused]] float elapsedSec) {};
		virtual void FixedUpdate([[maybe_unused]] float m_fixedTimeStep) {};
		Component& operator=(const Component& other) = delete;
		Component& operator=(Component&& other) = delete;

		virtual Component& referToThis() = 0;

		GameObject* GetGameObject() const
		{
			return m_pOwner;
		}
	private:
		GameObject* m_pOwner{};


	protected:
	};
}





