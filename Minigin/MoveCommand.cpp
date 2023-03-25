#include "MoveCommand.h"

dae::MoveCommand::MoveCommand(dae::GameObject* actor)
	: GameObjectCommand(actor)
	, m_Speed{ 0.f }
	, m_DirectionVector{0.f,0.f,0.f}
{
}

void dae::MoveCommand::Execute()
{
}
