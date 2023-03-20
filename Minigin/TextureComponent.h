#pragma once
#include "Component.h"
#include <iostream>
#include "Texture2D.h"
#include "ResourceManager.h"

namespace dae
{
	class Transform;
	class Texture2D;
	class TextureComponent : public Component
	{
	public:
		TextureComponent(GameObject* pOwner, const std::string& filePath, bool drawAroundCenter);
		TextureComponent(GameObject* pOwner, bool drawAroundCenter);
		~TextureComponent();
		void Update(float elapsedSec);
		void Render() const;
		const Texture2D& GetTexture();
		void SetTexture(const std::string& filename) { m_pTexture2D = ResourceManager::GetInstance().LoadTexture(filename); };
		TextureComponent& referToThis() override { return *this; };
		void SetTexture(std::shared_ptr<Texture2D> texture);
		glm::ivec2 GetTextureSize() const;


	private:
		std::shared_ptr<Texture2D> m_pTexture2D; 
		Transform* m_pOwnerTransform{};
		bool m_drawAroundCenter{};
	};
}
