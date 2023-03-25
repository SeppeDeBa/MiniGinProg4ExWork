#pragma once
#include "GameObjectCommand.h"
#include "MyUtils.h"
#include "GameObject.h"
namespace dae
{

	class MoveCommand : public dae::GameObjectCommand
	{
	public:
		MoveCommand(GameObject* actor);
		~MoveCommand();
		void Execute() override;
	private:
		Vector3f m_DirectionVector;
		float m_Speed;

	};
}
