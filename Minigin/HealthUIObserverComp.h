#pragma once
#include "GameObjectObserver.h"
#include "TextComponent.h"
#include "HealthComponent.h"
namespace dae
{
	//TODO: Think about combining this with scoreUIObserverComp
	class HealthUIObserverComp final : public GameObjectObserver, public TextComponent
	{
	public:
		HealthUIObserverComp(GameObject* pGOOwner, const int playerNumber, GameObject* pGOToWatch, std::shared_ptr<Font> font)
			: TextComponent(pGOOwner,
				GetOutputString(playerNumber, pGOToWatch->GetComponent<HealthComponent>()->GetHealth()), 
				font)
			, GameObjectObserver(pGOToWatch, SubjectBase::messageTypes::HEALTHSYSTEM)
			, m_playerNumber{ playerNumber }
		{};
		~HealthUIObserverComp() {};
		void Update(float deltaTime) { TextComponent::Update(deltaTime); }; //does this need to happen manually? I don't think so but not sure
		void OnNotify() override
		{
			//TODO: Simplify this to store things locally maybe, although this doesn't happen that often.
			SetText(GetOutputString(m_playerNumber, GetWatchedGO()->GetComponent<HealthComponent>()->GetHealth()));
		}

	private:
		const int m_playerNumber;

		// helper function
		std::string GetOutputString(const int playerNumber, int healthValue) const
		{
			std::string outputString{ "player " };
			outputString += std::to_string(playerNumber);
			outputString += "health: ";
			outputString += std::to_string(healthValue);
			return outputString;
		};
	};
}

