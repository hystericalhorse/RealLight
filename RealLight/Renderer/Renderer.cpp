#include "Renderer.h"
#include "Math/MathUtils.h"
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

	void Renderer::Render(Canvas& canvas, Scene& scene, Camera& camera, int samples)
	{
		for (int y = 0; y < canvas.GetHeight(); y++)
		{
			for (int x = 0; x < canvas.GetWidth(); x++)
			{
				color3 color{ 0 };
				for (int i = 0; i < samples; i++)
				{
					glm::vec2 point = glm::vec2{ randomDecimal() + x, randomDecimal() + y } / glm::vec2{ canvas._width, canvas._height };

					point.y = 1.0f - point.y;

					Ray ray = camera.PointToRay(point);

					RaycastHit raycastHit;
					color += scene.Trace(ray, 0.01, 1000.0, raycastHit, 5);
				}

				color = color / color3(samples);
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