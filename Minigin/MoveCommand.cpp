#include "MoveCommand.h"
#include <iostream> //for debugging
dae::MoveCommand::MoveCommand(dae::GameObject* actor, float speed, glm::vec2 moveDirection)
	: GameObjectCommand(actor)
	, m_Speed{ speed }
	, m_DirectionVector{moveDirection}
{
}

dae::MoveCommand::~MoveCommand()
{
}

void dae::MoveCommand::Execute(float deltaTime)
{
	std::cout << "Move Command Fired" << std::endl;
	m_pGameObject->GetComponent<dae::Transform>()->AddToLocalPosition(m_DirectionVector.x * m_Speed * deltaTime , (m_DirectionVector.y*-1) * m_Speed * deltaTime); //inverting direction vector because y.0 = at the top of the screen
}

void dae::MoveCommand::SetSpeed(float speed)
{
	m_Speed = speed;
}
