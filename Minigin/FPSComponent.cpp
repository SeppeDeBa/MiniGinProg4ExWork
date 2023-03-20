#include "FPSComponent.h"
#include <string>
dae::FPSComponent::FPSComponent(GameObject* pOwner)
	: Component(pOwner)
	, m_FPS{ 0 }
	, m_time{ 0 }
	, m_FPSPerSec{0}
	
{
}

dae::FPSComponent::~FPSComponent()
{
	m_pOwnersTextComponent = nullptr;
}

void dae::FPSComponent::Update(float deltaTime)
{
	m_time += deltaTime;
	m_FPS += 1;
	//This happens once per second roughly
	if (m_time >= 1.f)
	{
		m_FPSPerSec = (int)m_FPS;
		m_time = 0.f;
		m_FPS = 0.f;

		if (m_pOwnersTextComponent == nullptr && GetGameObject()->GetComponent<TextComponent>())
		{
			m_pOwnersTextComponent = GetGameObject()->GetComponent<TextComponent>();
			//will sadly check every frame if there is none present in the GameObject, should I set a timer on this?
		}
		else //this will not happen the first second... not really a problem
		{
			std::string outputFpsString(std::to_string(m_FPSPerSec) + " FPS");
			m_pOwnersTextComponent->SetText(outputFpsString);
			//will sadly check every frame if there is none present in the GameObject, should I set a timer on this?
		}
	}


}

void dae::FPSComponent::SetFPS(const float& FPS)
{
	m_FPS = FPS;
}

int dae::FPSComponent::GetFPS() const
{
	return m_FPSPerSec;
}
