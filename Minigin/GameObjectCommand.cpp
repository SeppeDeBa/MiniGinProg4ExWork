#include "GameObjectCommand.h"

dae::GameObjectCommand::GameObjectCommand(GameObject* actor)
	:m_pGameObject{actor}
{
}

dae::GameObjectCommand::~GameObjectCommand()
{
	m_pGameObject = nullptr;
}

dae::GameObject* dae::GameObjectCommand::GetGameActorPtr() const
{
	return m_pGameObject;
}
