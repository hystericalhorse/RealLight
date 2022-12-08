#include "RealLight.h"

using namespace std;

int main(int, char**)
{
	const int width		= 800;
	const int height	= 400;

	const int samples	= 1;


	// Init
	RealLight::Renderer renderer;

	renderer.Init();
	renderer.CreateWindow(width, height);

	RealLight::Scene scene;

	RealLight::Canvas canvas(width, height, renderer);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0, 0.3, -1 }, 0.2f, std::make_unique<RealLight::Metal>(color3{ 1, 1, 1 }, 0.2)
		)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0.5, 0.3, -1 }, 0.1f, std::make_unique<RealLight::Lambert>(color3{ 0, 1, 1 })
		)
	);

	//scene.addObject
	//(
	//	std::make_unique<RealLight::Sphere>
	//	(
	//		glm::vec3{ 0, -0.6, -1 }, 0.5f, std::make_unique<RealLight::Metal>(color3{ 1 })
	//	)
	//);

	scene.addObject
	(
		std::make_unique<RealLight::Plane>
		(
			glm::vec3{0, 0.1, 0}, glm::vec3{0, 1, 0}, std::make_unique<RealLight::Lambert>(color3{0.5, 0, 0.5})
		)
	);

	RealLight::Camera camera({ 0, 0.5, -4.0 }, { 0, 0, 0 }, { 0, 1, 0 }, 20.0f, width / (float) height);

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
		
		renderer.Render(canvas, scene, camera, samples);
		
		canvas.Update();

		renderer.CopyCanvas(canvas);
		renderer.Present();
	}

	// Shutdown
	renderer.Shutdown();
	return 0;
}