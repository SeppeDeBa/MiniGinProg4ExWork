#pragma once
#include "Component.h"
#include <glm/glm.hpp>
namespace dae
{
	class Transform;
	class TextureComponent;
	class RotatorComponent : public Component
	{
	public:
		RotatorComponent(GameObject* pOwner, float radius, float rotationSpeedPerSec, bool goesClockwise, float startingRotation);
		RotatorComponent(GameObject* pOwner, float radius, float rotationSpeedPerSec, bool goesClockwise);
		~RotatorComponent();
		RotatorComponent& referToThis() override { return *this; };
		void Update(float elapsedSec);
	
	private:
	
		float m_circleRadius;
		float m_angle;
		float m_rotationSpeedPerSec;
		bool m_goesClockwise;
		Transform* m_pOwnerTransform{};
		TextureComponent* m_pOwnerTextureComponent{};
	};
}
