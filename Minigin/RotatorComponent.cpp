#include "RotatorComponent.h"
#include "Transform.h"
#include "TextureComponent.h"
#define _USE_MATH_DEFINES
#include <math.h>

dae::RotatorComponent::RotatorComponent(GameObject* pOwner, float radius, float rotationSpeedPerSec, bool goesClockwise, float startingAngle)
	: Component(pOwner)
	, m_circleRadius{radius}
	, m_rotationSpeedPerSec{rotationSpeedPerSec}
	, m_goesClockwise{goesClockwise}
	, m_angle{startingAngle}
{
 
}

dae::RotatorComponent::RotatorComponent(GameObject* pOwner, float radius, float rotationSpeedPerSec, bool goesClockwise)
	: Component(pOwner)
	, m_circleRadius{ radius }
	, m_rotationSpeedPerSec{rotationSpeedPerSec}
	, m_goesClockwise{ goesClockwise }
	, m_angle{ 0.f }
{

}

dae::RotatorComponent::~RotatorComponent()
{
	if (m_pOwnerTransform != nullptr)
	{
		m_pOwnerTransform = nullptr;
	}
	if (m_pOwnerTextureComponent != nullptr)
	{
		m_pOwnerTextureComponent = nullptr;
	}
}

void dae::RotatorComponent::Update(float elapsedSec)
{
	//Calculate new angle
	if (m_goesClockwise)
	{
		m_angle -= m_rotationSpeedPerSec * elapsedSec;
	}
	else
	{
		m_angle += m_rotationSpeedPerSec * elapsedSec;
	}

	//Check Both pointers to components of GameObject owner
	if (m_pOwnerTransform == nullptr)
	{
		m_pOwnerTransform = GetGameObject()->GetComponent<Transform>();
	}
	if (m_pOwnerTextureComponent == nullptr)
	{
		m_pOwnerTextureComponent = GetGameObject()->GetComponent<TextureComponent>();
	}
	
	//Set rotation to the center of a textureComponent
	if (m_pOwnerTransform != nullptr && m_pOwnerTextureComponent != nullptr)
	{
		m_pOwnerTransform->SetLocalPosition(cos(m_angle * (float)M_PI / 180.f) * m_circleRadius /*+ (m_pOwnerTextureComponent->GetTextureSize().x/2.f)*/
										  , sin(m_angle * (float)M_PI / 180.f) * m_circleRadius /*+ (m_pOwnerTextureComponent->GetTextureSize().y / 2.f)*/);
	}

	//Set rotation to the center of only a transformation
	else if (m_pOwnerTextureComponent != nullptr)
	{

	}
	
}
