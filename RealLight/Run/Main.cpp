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
			glm::vec3{ 0, 0.3, -1 }, 0.2f, std::make_unique<RealLight::Lambert>(color3{ 0, 1, 1 })
		)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0, 0, -1 }, 0.1f, std::make_unique<RealLight::Lambert>(color3{ 1, 0, 1 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0, -0.2, -1 }, 0.1f, std::make_unique<RealLight::Lambert>(color3{ 1, 0, 0 })
			)
	);

	RealLight::Camera camera({ 0, 0, -1.5 }, { 0, 0, 0 }, { 0, 1, 0 }, 60.0f, 400 / (float) 200);

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
		
		renderer.Render(canvas, scene, camera);
		
		canvas.Update();

		renderer.CopyCanvas(canvas);
		renderer.Present();
	}

	// Shutdown
	renderer.Shutdown();
	return 0;
}