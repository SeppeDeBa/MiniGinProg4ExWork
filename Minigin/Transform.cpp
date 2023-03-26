#include "Transform.h"

dae::Transform::Transform(GameObject* pOwner, float x, float y)
	: Component(pOwner)
	, m_localPosition{ x, y, 0.f }
{
}

dae::Transform::Transform(GameObject* pOwner, float x, float y, float z)
	: Component(pOwner)
	, m_localPosition{ x, y, z }
{
}

dae::Transform::~Transform()
{
}

void dae::Transform::Update([[maybe_unused]]float elapsedSec)
{
	UpdateWorldPosition();
}

void dae::Transform::SetLocalPosition(const float x, const float y, const float z)
{
	m_localPosition.x = x;
	m_localPosition.y = y;
	m_localPosition.z = z;
	GetGameObject()->SetPositionDirty();
}

void dae::Transform::SetLocalPosition(const float x, const float y)
{
	m_localPosition.x = x;
	m_localPosition.y = y;
	GetGameObject()->SetPositionDirty();
}

void dae::Transform::SetLocalPosition(const glm::vec3& vecInput)
{
	m_localPosition = vecInput;
	GetGameObject()->SetPositionDirty();
}

void dae::Transform::AddToLocalPosition(float x, float y)
{
	m_localPosition.x += x;
	m_localPosition.y += y;
	GetGameObject()->SetPositionDirty();
}

void dae::Transform::AddToLocalPosition(float x, float y, float z)
{
	m_localPosition.x += x;
	m_localPosition.y += y;
	m_localPosition.z += z;
	GetGameObject()->SetPositionDirty();
}

void dae::Transform::SetDirty()
{
	m_positionIsDirty = true;
}

void dae::Transform::UpdateWorldPosition()
{
	if (m_positionIsDirty)
	{
		if (GetGameObject()->GetParent() == nullptr)
		{
			m_worldPosition = m_localPosition;
		}
		else
		{
			m_worldPosition = GetGameObject()-> GetParent()-> GetComponent<Transform>()-> GetWorldPosition() + m_localPosition;
			//need to optimise this by saving some of this data in members! such as: Parent or Parent Transform even.
		}
	}
	m_positionIsDirty = false;
}

glm::vec3 dae::Transform::GetWorldPosition()
{
	if (m_positionIsDirty)
	{
		UpdateWorldPosition();
	}
	return m_worldPosition;
}

