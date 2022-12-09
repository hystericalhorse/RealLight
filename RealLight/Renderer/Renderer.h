#pragma once

#include "Canvas.h"
#include "Math/Ray.h"
#include "Objects/Object.h"
#include "Renderer/Scene.h"
#include "Renderer/Camera.h"

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

		void Render(Canvas& canvas, Scene& scene, Camera& camera, int samples = 5);

		void CopyCanvas(const Canvas& canvas);
		void Present();

		friend class Canvas;
	protected:
		color3 GetBackgroundByRay(const Ray& ray);

		SDL_Window* _window{ nullptr };
		SDL_Renderer* _renderer{ nullptr };

	};
}