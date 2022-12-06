#include "RealLight.h"

using namespace std;

int main(int, char**)
{
	// Init
	RealLight::Renderer renderer;

	renderer.Init();
	renderer.CreateWindow(400, 200);

	RealLight::Scene scene;

	RealLight::Canvas canvas(400, 200, renderer);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0, 0, -0.5 }, 0.2f, std::make_unique<RealLight::Lambert>(color3{ 0, 1, 0 })
		)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0.2, -0.7, -0.5 }, 0.5f, std::make_unique<RealLight::Lambert>(color3{ 1, 0, 0 })
		)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ -0.2, 1.2, -0.5 }, 1.0f, std::make_unique<RealLight::Lambert>(color3{ 0, 0, 1 })
			)
	);

	// Run
	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;
			}
			break;
		}

		// Render
		canvas.Clear({0,0,0,1});
		
		renderer.Render(canvas, scene);
		
		canvas.Update();

		renderer.CopyCanvas(canvas);
		renderer.Present();
	}

	// Shutdown
	renderer.Shutdown();
	return 0;
}