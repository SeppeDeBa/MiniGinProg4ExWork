#pragma once
#include "GameObjectCommand.h"
#include "ScoreComponent.h"
namespace dae
{
	class ScoreCommand :public GameObjectCommand
	{
	public:
		ScoreCommand(GameObject* actor, int scoreToAdd = 100)
			: GameObjectCommand(actor)
			, m_ScoreToAdd{scoreToAdd}
		{

		}
		~ScoreCommand() {};
		void Execute([[maybe_unused]] float deltaTime) override
		{
			if (m_pGameObject != nullptr)m_pGameObject->GetComponent<ScoreComponent>()->AddScore(m_ScoreToAdd);
		}
	private:
		int m_ScoreToAdd;
	};
}

