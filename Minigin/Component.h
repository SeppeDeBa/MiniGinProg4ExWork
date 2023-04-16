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
		virtual void Render() const {};
		virtual void Update([[maybe_unused]] float elapsedSec) {};//empty initialise for components that don't need an update or fixed update, so they just call the empty function here.
		virtual void FixedUpdate([[maybe_unused]] float m_fixedTimeStep) {};
		Component(const Component& other) = delete;
		Component(Component&& other) = delete;
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





