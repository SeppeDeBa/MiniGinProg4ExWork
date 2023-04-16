#pragma once
#include "Component.h"
namespace dae
{
	class HealthComponent final: public Component 
	{
	public:
		HealthComponent(GameObject* pOwner, int startingHealth, bool startsAlive = true)
			: Component(pOwner)
			, m_health{startingHealth}
			, m_isAlive{ startsAlive }
		{
		};
		~HealthComponent() {};
		void TakeDamage(int damageDone = 1) 
		{
			if (m_isAlive)
			{
				m_health -= damageDone;
				if (m_health <= 0)
				{
					m_isAlive = false;
				}
				GetGameObject()->Notify(SubjectBase::messageTypes::HEALTHSYSTEM);
			}
		};

		Component& referToThis() override { return *this; };
		int GetHealth() { return m_health; };

	private:

		int m_health;
		bool m_isAlive;

	};
}

