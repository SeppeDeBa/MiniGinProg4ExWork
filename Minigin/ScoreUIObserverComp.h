#pragma once
#include "GameObjectObserver.h"
#include "TextComponent.h"
#include "ScoreComponent.h"
namespace dae
{
	class ScoreUIObserverComp : public GameObjectObserver, public TextComponent
	{
	public:
		ScoreUIObserverComp(GameObject* pGOOwner, const int playerNumber, GameObject* pGOToWatch, std::shared_ptr<Font> font)
			: TextComponent(pGOOwner,
				GetOutputString(playerNumber, pGOToWatch->GetComponent<ScoreComponent>()->GetScore()),
				font)
			, GameObjectObserver(pGOToWatch, SubjectBase::messageTypes::SCORESYSTEM)
			, m_playerNumber{ playerNumber }
		{};
		~ScoreUIObserverComp() {};
		void Update(float deltaTime) { TextComponent::Update(deltaTime); }; //does this need to happen manually? I don't think so but not sure
		void OnNotify() override
		{
			//TODO: Simplify this to store things locally maybe, although this doesn't happen that often.
			SetText(GetOutputString(m_playerNumber, GetWatchedGO()->GetComponent<ScoreComponent>()->GetScore()));
		}

	private:
		const int m_playerNumber;

		// helper function
		std::string GetOutputString(const int playerNumber, int scoreValue) const
		{
			std::string outputString{ "player " };
			outputString += std::to_string(playerNumber);
			outputString += " score is: ";
			outputString += std::to_string(scoreValue);
			return outputString;
		}
		
	};
}

