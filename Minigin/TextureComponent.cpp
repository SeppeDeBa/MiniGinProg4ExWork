#include "TextureComponent.h"
#include "Texture2D.h"
#include "Renderer.h"
#include "Transform.h"
#include <iostream>
dae::TextureComponent::TextureComponent(GameObject* pOwner, const std::string& filePath, bool drawAroundCenter)
	: Component(pOwner)
	, m_pTexture2D{ ResourceManager::GetInstance().LoadTexture(filePath) }
	, m_drawAroundCenter{ drawAroundCenter }
{

}

dae::TextureComponent::TextureComponent(GameObject* pOwner, bool drawAroundCenter)
	: Component(pOwner)
	, m_pTexture2D{}
	, m_drawAroundCenter{ drawAroundCenter }
{

}



dae::TextureComponent::~TextureComponent()
{
	if (m_pTexture2D != nullptr)
	{
		m_pTexture2D = nullptr;
	}
	if (m_pOwnerTransform != nullptr)
	{
		m_pOwnerTransform = nullptr;
	}
}


void dae::TextureComponent::Update([[maybe_unused]]float elapsedSec)
{
	if (m_pOwnerTransform == nullptr)
	{
		m_pOwnerTransform = GetGameObject()->GetComponent<Transform>();
	}
}

void dae::TextureComponent::Render() const
{
	if (m_pTexture2D != nullptr && m_pOwnerTransform != nullptr)
	{
		if (m_drawAroundCenter)
		{
			Renderer::GetInstance().RenderTexture(*m_pTexture2D
				, m_pOwnerTransform->GetWorldPosition().x - GetTextureSize().x / 2.f
				, m_pOwnerTransform->GetWorldPosition().y - GetTextureSize().y / 2.f);
		}
		else
		{

			Renderer::GetInstance().RenderTexture(*m_pTexture2D
				, m_pOwnerTransform->GetWorldPosition().x
				, m_pOwnerTransform->GetWorldPosition().y);
		}
	}
}

const dae::Texture2D& dae::TextureComponent::GetTexture()
{
	return *m_pTexture2D;
}

void dae::TextureComponent::SetTexture(std::shared_ptr<Texture2D> texture)
{
	m_pTexture2D = texture;
}

glm::ivec2 dae::TextureComponent::GetTextureSize() const
{
	return m_pTexture2D->GetSize();
}

