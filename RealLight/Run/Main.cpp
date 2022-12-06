#include "RealLight.h"

using namespace std;

int main(int, char**)
{
	// Init
	RealLight::Renderer renderer;

	renderer.Init();
	renderer.CreateWindow(1200, 600);

	RealLight::Canvas canvas(1200, 600, renderer);

	auto sphere = std::make_unique<RealLight::Sphere>(glm::vec3{ 0, 0, 1 }, 0.5f, nullptr);

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
		
		renderer.Render(canvas, sphere.get());
		
		canvas.Update();

		renderer.CopyCanvas(canvas);
		renderer.Present();
	}

	// Shutdown
	renderer.Shutdown();
	return 0;
}