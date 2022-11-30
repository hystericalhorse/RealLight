#include "Renderer.h"
#include <iostream>

namespace RealLight
{
	bool Renderer::Init()
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			std::cout << "SDLError: " << SDL_GetError() << std::endl;
			return false;
		}

		return true;
	}

	void Renderer::Shutdown()
	{
		if (_window) SDL_DestroyWindow(_window);
		if (_renderer) SDL_DestroyRenderer(_renderer);
		SDL_Quit();
	}

	bool Renderer::CreateWindow(int width, int height)
	{
		_window = SDL_CreateWindow("RealLight", 100, 100, width, height, SDL_WINDOW_SHOWN);
		if (_window == nullptr)
		{
			std::cout << "SDL Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
			return false;
		}
		_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (_renderer == nullptr)
		{
			std::cout << "SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}
		return true;
	}
}