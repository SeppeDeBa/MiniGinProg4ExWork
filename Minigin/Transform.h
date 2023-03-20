#pragma once
#include <glm/glm.hpp>
#include "Component.h"
namespace dae
{
	class Transform final : public Component
	{
	public:
		Transform(GameObject* pOwner, float x, float y);
		Transform(GameObject* pOwner, float x, float y, float z);
		~Transform();
		void Update(float elapsedSec);
		const glm::vec3& GetLocalPosition() const { return m_localPosition; };
		void SetLocalPosition(float x, float y, float z);
		void SetLocalPosition(float x, float y);
		void SetLocalPosition(const glm::vec3& vecInput);
		Transform& referToThis() override { return *this; };
		void SetDirty();
		
		void UpdateWorldPosition();
		glm::vec3 GetWorldPosition();

	private:
		glm::vec3 m_localPosition;
		glm::vec3 m_worldPosition{}; // empty initialise
		bool m_positionIsDirty{ true };

	};
}
