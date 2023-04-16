#pragma once
#include "GameObjectCommand.h"
#include "HealthComponent.h"
namespace dae
{
	class DamageCommand final : public GameObjectCommand
	{
	public:
		DamageCommand(GameObject* actor, int damageToTake = 1)
			:GameObjectCommand(actor)
			, m_damageToTake{damageToTake}
		{

		}
		~DamageCommand() {};
		void Execute([[maybe_unused]] float deltaTime) override
		{
			if(m_pGameObject!=nullptr)m_pGameObject->GetComponent<HealthComponent>()->TakeDamage(m_damageToTake);
		}
	private:

		int m_damageToTake;
	};
}

