#pragma once
#include <glm/glm.hpp>
#include "GameObjectCommand.h"
#include "MyUtils.h"
#include "GameObject.h"
#include "Transform.h"
namespace dae
{

	class MoveCommand : public dae::GameObjectCommand
	{
	public:
		MoveCommand(GameObject* actor, float speed = 0);
		~MoveCommand();
		void Execute(float deltaTime) override;
		void SetSpeed(float speed);
	private:
		float m_Speed;
		glm::vec2 m_DirectionVector;

	};
}
