#pragma once
#include "Component.h"
//TODO:make a class that can be used for both this and health for easy reusability (only when needed, think about this)
namespace dae
{
	class ScoreComponent : public Component
	{
	public:
		ScoreComponent(GameObject* pOwner, int startingScore = 0)
			: Component(pOwner)
			, m_score{startingScore}
		{

		}
		~ScoreComponent() {};
		void AddScore(int scoreToAdd = 100)
		{
			m_score += scoreToAdd;
			GetGameObject()->Notify(SubjectBase::messageTypes::SCORESYSTEM);
		}
	
		//TODO: remove the need for the referToThis in all, was used in an older system
		Component& referToThis() { return *this; };
		int GetScore() { return m_score; };
	
	private:
		int m_score;
	
	};
}

