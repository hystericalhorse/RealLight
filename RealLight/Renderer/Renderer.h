#pragma once

#include <SDL.h>

namespace RealLight
{
	class Renderer
	{
	public:
		Renderer() = default;

		bool Init();
		void Shutdown();
		bool CreateWindow(int width, int height);

	private:
		SDL_Window* _window{ nullptr };
		SDL_Renderer* _renderer{ nullptr };

	};
}