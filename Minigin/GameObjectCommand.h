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
		virtual void Execute() = 0;
	protected:
		GameObject* GetGameActorPtr() const;
	private:
		GameObject* m_GameObject;
	};
}


