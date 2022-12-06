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

	void Renderer::Render(Canvas& canvas, Scene& scene)
	{
		glm::vec3 lowerLeft{ -2, -1, -1 };
		glm::vec3 eye{ 0, 0, 0 };
		glm::vec3 right{ 4, 0, 0 };
		glm::vec3 up{ 0, 2, 0 };

		for (int y = 0; y < canvas.GetHeight(); y++)
		{
			for (int x = 0; x < canvas.GetWidth(); x++)
			{
				float u = x / (float)canvas.GetWidth();
				float v = 1 - (y / (float)canvas.GetHeight());

				glm::vec3 direction = lowerLeft + (u * right) + (v * up);
				Ray ray{ eye, direction };

				RaycastHit raycastHit;
				color3 color = scene.Trace(ray, 0.01, 1000.0, raycastHit, 5);

				canvas.DrawPoint({ x, y }, color4(color, 1));
			}
		}
	}

	void Renderer::CopyCanvas(const Canvas& canvas)
	{
		SDL_RenderCopy(_renderer, canvas._texture, nullptr, nullptr);
	}

	void Renderer::Present()
	{
		SDL_RenderPresent(_renderer);
	}

	color3 Renderer::GetBackgroundByRay(const Ray& ray)
	{
		glm::vec3 direction = glm::normalize(ray.dir);
		float t = 0.5f * (direction.y + 1.0f);

		return twerp(color3{ 0.0f, 0.0f, 0.6f }, color3{ 0.4f, 0.0f, 0.4f }, t);
	}
}