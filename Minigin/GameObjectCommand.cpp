#include "GameObjectCommand.h"

dae::GameObjectCommand::GameObjectCommand(GameObject* actor)
	:m_GameObject{actor}
{
}

dae::GameObjectCommand::~GameObjectCommand()
{
	m_GameObject = nullptr;
}

dae::GameObject* dae::GameObjectCommand::GetGameActorPtr() const
{
	return m_GameObject;
}
