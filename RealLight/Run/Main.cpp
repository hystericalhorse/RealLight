#include <iostream>
#include "RealLight.h"

using namespace std;

int main(int, char**)
{
	// Init
	RealLight::Renderer renderer;

	renderer.Init();
	renderer.CreateWindow(800, 600);

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
		}
	}

	// Shutdown
	renderer.Shutdown();
	return 0;
}