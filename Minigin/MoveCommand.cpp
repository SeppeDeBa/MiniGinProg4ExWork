#include "MoveCommand.h"
#include <iostream> //for debugging
dae::MoveCommand::MoveCommand(dae::GameObject* actor, float speed)
	: GameObjectCommand(actor)
	, m_Speed{ speed }
	, m_DirectionVector{0.f,0.f}
{
}

dae::MoveCommand::~MoveCommand()
{
}

void dae::MoveCommand::Execute(float deltaTime)
{
	std::cout << "Move Command Fired" << std::endl;
	m_pGameObject->GetComponent<dae::Transform>()->AddToLocalPosition(m_DirectionVector.x * m_Speed * deltaTime , m_DirectionVector.y * m_Speed * deltaTime);
}

void dae::MoveCommand::SetSpeed(float speed)
{
	m_Speed = speed;
}
