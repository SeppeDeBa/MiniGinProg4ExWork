#pragma once
#include "Component.h"
#include <string>
#include <memory>
#include "GameObject.h"

namespace dae
{
	class Transform;
	class TextureComponent;
	class Font;
	class Texture2D;
	class TextComponent final : public Component
	{
	public:
		TextComponent(GameObject* pOwner, const std::string& text, std::shared_ptr<Font> font);
	
		~TextComponent() = default;
		void Update( float deltaTime);
		void SetText(const std::string& text);
		TextComponent& referToThis() override { return *this; };

	private:
		bool m_needsUpdate;
		std::string m_textString;
		std::shared_ptr<Font> m_font;
	};

}

