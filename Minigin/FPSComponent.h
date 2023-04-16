#pragma once
#include "Component.h"
#include "TextComponent.h"
//#include "GameObject.h"

namespace dae
{
	class TextComponent;
	
	class FPSComponent : public Component
	{
	public:
		FPSComponent(GameObject* pOwner);
		~FPSComponent();
		void Update(float deltaTime);
		void SetFPS(const float& FPS);
		int GetFPS() const;
		FPSComponent& referToThis() override { return *this; };
	private:
		float m_FPS;
		float m_time;
		int m_FPSPerSec;
		TextComponent* m_pOwnersTextComponent{};
	};
}