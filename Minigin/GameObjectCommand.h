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
		virtual void Execute(float deltaTime) = 0;

		GameObjectCommand(const GameObjectCommand& other) = delete;
		GameObjectCommand(GameObjectCommand&& other) = delete;
		GameObjectCommand& operator=(const GameObjectCommand& other) = delete;
		GameObjectCommand& operator=(GameObjectCommand&& other) = delete;

	protected:
		GameObject* GetGameActorPtr() const;//no purpose?
		GameObject* m_pGameObject;
	private:
	};
}


