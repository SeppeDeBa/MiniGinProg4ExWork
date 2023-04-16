#pragma once
#include "GameObjectCommand.h"
#include "HealthComponent.h"
namespace dae
{
	class DamageCommand final : public GameObjectCommand
	{
	public:
		DamageCommand(GameObject* actor)
			:GameObjectCommand(actor)
		{

		}
		~DamageCommand() {};
		void Execute([[maybe_unused]]float deltaTime) override
		{
			m_pGameObject->GetComponent<HealthComponent>()->TakeDamage();
		}
	private:

	};
}

