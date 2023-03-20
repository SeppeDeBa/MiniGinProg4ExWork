#pragma once
#include <SDL.h>
#include "Singleton.h"

#include "imgui.h"
#include "imgui_plot.h"

#include "imgui_impl_opengl2.h"
#include "imgui_impl_sdl2.h"

//trash the cache includes:
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>


namespace dae
{
	class Texture2D;
	/**
	 * Simple RAII wrapper for the SDL renderer
	 */
	class Renderer final : public Singleton<Renderer>
	{
		SDL_Renderer* m_renderer{};
		SDL_Window* m_window{};
		bool m_showDemo{};
		SDL_Color m_clearColor{};	

	public:
		void Init(SDL_Window* window);
		void Render() const;
		void Destroy();

		void RenderTexture(const Texture2D& texture, float x, float y) const;
		void RenderTexture(const Texture2D& texture, float x, float y, float width, float height) const;

		SDL_Renderer* GetSDLRenderer() const;
		const SDL_Color& GetBackgroundColor() const { return m_clearColor; }
		void SetBackgroundColor(const SDL_Color& color) { m_clearColor = color; }
		
	
	
	};
}

