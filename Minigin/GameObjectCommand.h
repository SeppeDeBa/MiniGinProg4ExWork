#pragma once
#include "Command.h"
#include "GameObject.h"
namespace dae
{
	class GameObjectCommand : public Command 
	{
	public:
		GameObjectCommand(GameObject* actor);
		virtual ~GameObjectCommand();
		virtual void Execute(float [[maybe_unused]] deltaTime) = 0;
	protected:
		GameObject* GetGameActorPtr() const;
		GameObject* m_pGameObject;
	private:
	};
}


