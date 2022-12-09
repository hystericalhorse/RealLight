#include "RealLight.h"

using namespace std;

void Default(RealLight::Scene& scene)
{
	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0, 0.3, -1 }, 0.2f, std::make_unique<RealLight::Metal>(color3{ 1, 1, 1 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0.5, 0.3, -2 }, 0.2f, std::make_unique<RealLight::Metal>(color3{ 1, 0, 1 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ -0.5, 0.3, -2 }, 0.2f, std::make_unique<RealLight::Dielectric>(color3{ 1 }, 1.5)
			)
	);

	/*scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0.5, 10, -1 }, 0.1f, std::make_unique<RealLight::Emissive>(color3{ 100 })
			)
	);*/

	scene.addObject
	(
		std::make_unique<RealLight::Plane>
		(
			glm::vec3{ 0, 0.1, 0 }, glm::vec3{ 0, 1, 0 }, std::make_unique<RealLight::Lambert>(color3{ 0.2,0.2,0.2 })
			)
	);
}

void Marbles(RealLight::Scene& scene)
{
	scene.addObject(std::make_unique<RealLight::Sphere>(glm::vec3{ 0, 1, 0 }, 1.0f, std::make_unique<RealLight::Dielectric>(color3{ 1.0f, 1.0f, 1.0f }, 1.5f)));
	scene.addObject(std::make_unique<RealLight::Sphere>(glm::vec3{ -4, 1, 0 }, 1.0f, std::make_unique<RealLight::Lambert>(color3{ 0.4f, 0.2f, 0.1f })));
	scene.addObject(std::make_unique<RealLight::Sphere>(glm::vec3{ 4, 1, 0 }, 1.0f, std::make_unique<RealLight::Metal>(color3{ 0.7f, 0.6f, 0.5f }, 0.0f)));

	scene.addObject(std::make_unique<RealLight::Plane>(glm::vec3{ 0, 0, 0 }, glm::vec3{ 0, 1, 0 }, std::make_unique<RealLight::Lambert>(color3{ 0.5f, 0.5f, 0.5f })));

	for (int x = -11; x < 11; x++)
	{
		for (int z = -11; z < 11; z++)
		{
			glm::vec3 center(x + 0.9f * randomBinary(), 0.2f, z + 0.9f * randomBinary());

			if ((center - glm::vec3{ 4, 0.2, 0 }).length() > 0.9f)
			{
				std::unique_ptr<RealLight::Material> material;

				float choose_mat = randomBinary();
				if (choose_mat < 0.8f)
				{
					color3 albedo = color3{ randomBinary(), randomBinary(), randomBinary() } *color3{ randomBinary(), randomBinary(), randomBinary() };
					material = std::make_unique<RealLight::Lambert>(albedo);
				}
				else if (choose_mat < 0.95)
				{
					color3 albedo = color3{ randomf(0.5f, 1), randomf(0.5f, 1), randomf(0.5f, 1) };
					float fuzz = randomf(0.0f, 0.5f);
					material = std::make_unique<RealLight::Metal>(albedo, fuzz);
				}
				else
				{
					color3 albedo = color3{ 1, 1, 1 };
					material = std::make_unique<RealLight::Dielectric>(albedo, 1.5f);
				}

				scene.addObject(std::make_unique<RealLight::Sphere>(center, 0.2f, std::move(material)));
			}
		}
	}
}

void Tube(RealLight::Scene& scene)
{
	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0, -5, 0 }, 2.0f, std::make_unique<RealLight::Lambert>(color3{ 1, 0, 0 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0, 5, 0 }, 2.0f, std::make_unique<RealLight::Lambert>(color3{ 0, 1, 0 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 4, 3, 0 }, 2.0f, std::make_unique<RealLight::Lambert>(color3{ 0, 0, 1 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 4, -3, 0 }, 2.0f, std::make_unique<RealLight::Metal>(color3{ 1 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ -4, 3, 0 }, 2.0f, std::make_unique<RealLight::Dielectric>(color3{ 1 }, 0.5)
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ -4, 3, 0 }, 2.0f, std::make_unique<RealLight::Emissive>(color3{ 1000 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ -4, -3, 0 }, 2.0f, std::make_unique<RealLight::Lambert>(color3{ 0, 1, 0 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ -4, 0, -5 }, 2.0f, std::make_unique<RealLight::Lambert>(color3{ 0, 0, 1 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 4, 0, -5 }, 2.0f, std::make_unique<RealLight::Dielectric>(color3{ 1 }, 0.5)
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 4, 0, -5 }, 2.0f, std::make_unique<RealLight::Emissive>(color3{ 1000 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 2.1, 4, -5 }, 2.0f, std::make_unique<RealLight::Lambert>(color3{ 1, 0, 0 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 2.1, -4, -5 }, 2.0f, std::make_unique<RealLight::Lambert>(color3{ 0, 1, 0 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ -2.1, 4, -5 }, 2.0f, std::make_unique<RealLight::Metal>(color3{ 1 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ -2.1, -4, -5 }, 2.0f, std::make_unique<RealLight::Dielectric>(color3{ 1 }, 0.5)
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ -2.1, -4, -5 }, 2.0f, std::make_unique<RealLight::Emissive>(color3{ 1000 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0, -5, -9 }, 2.0f, std::make_unique<RealLight::Metal>(color3{ 1 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0, 5, -9 }, 2.0f, std::make_unique<RealLight::Dielectric>(color3{ 1 }, 0.5)
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0, 5, -9 }, 1.0f, std::make_unique<RealLight::Emissive>(color3{ 1000 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 4, 3, -9 }, 2.0f, std::make_unique<RealLight::Lambert>(color3{ 0, 0, 1 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 4, -3, -9 }, 2.0f, std::make_unique<RealLight::Metal>(color3{ 1 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ -4, 3, -9 }, 2.0f, std::make_unique<RealLight::Metal>(color3{ 1, 0, 0 })
			)
	);

	// Emissives
	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ -20, 0, 0 }, 0.2f, std::make_unique<RealLight::Emissive>(color3{ 100000, 0, 100000 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 20, 0, -5 }, 0.2f, std::make_unique<RealLight::Emissive>(color3{ 0, 100000, 100000 })
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0, 20, -9 }, 0.2f, std::make_unique<RealLight::Emissive>(color3{ 1000, 1000, 100000 })
			)
	);

	
}

void Circles(RealLight::Scene& scene)
{
	scene.addObject
	(
		std::make_unique<RealLight::Plane>
		(
			glm::vec3{ 0, -1, 0 }, glm::vec3{ 0, 1, 0 }, std::make_unique<RealLight::Lambert>(color3{ 0.2 })
			)
	);


	// Inner Circle
	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 3, 0, 3 }, 1.0f, std::make_unique<RealLight::Metal>(color3{ 0, 1, 1 }, 0.1)
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 4, 0, 0 }, 1.0f, std::make_unique<RealLight::Metal>(color3{ 0, 0, 1 }, 0.1)
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 3, 0, -3 }, 1.0f, std::make_unique<RealLight::Metal>(color3{ 1, 0, 1 }, 0.1)
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0, 0, -4 }, 1.0f, std::make_unique<RealLight::Metal>(color3{ 0, 1, 0 }, 0.1)
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ -3, 0, -3 }, 1.0f, std::make_unique<RealLight::Metal>(color3{ 1, 1, 0 }, 0.1)
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ -4, 0, 0 }, 1.0f, std::make_unique<RealLight::Metal>(color3{ 1, 0, 0 }, 0.1)
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ -3, 0, 3 }, 1.0f, std::make_unique<RealLight::Metal>(color3{ 0.6, 1, 0.4 }, 0.1)
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0, 0, 4 }, 1.0f, std::make_unique<RealLight::Metal>(color3{ 1, 0.4, 0.6 }, 0.1)
			)
	);

	// Outer Circle ///////////////////////////////////////////////////////////////////////////////////////
	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 12, 4, 12 }, 4.0f, std::make_unique<RealLight::Dielectric>(color3{ 1, 0.4, 0.6 }, 2.0)
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 16, 4, 0 }, 4.0f, std::make_unique<RealLight::Dielectric>(color3{ 0, 1, 1 }, 2.0)
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 12, 4, -12 }, 4.0f, std::make_unique<RealLight::Dielectric>(color3{ 0, 0, 1 }, 2.0)
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0, 4, -16 }, 4.0f, std::make_unique<RealLight::Dielectric>(color3{ 1, 0, 1 }, 2.0)
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ -12, 4, -12 }, 4.0f, std::make_unique<RealLight::Dielectric>(color3{ 0, 1, 0 }, 2.0)
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ -16, 4, 0 }, 4.0f, std::make_unique<RealLight::Dielectric>(color3{ 1, 1, 0 }, 2.0)
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ -12, 4, 12 }, 4.0f, std::make_unique<RealLight::Dielectric>(color3{ 1, 0, 0 }, 2.0)
			)
	);

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0, 4, 16 }, 4.0f, std::make_unique<RealLight::Dielectric>(color3{ 0.6, 1, 0.4 }, 2.0)
			)
	);


	// Skylight ////////////////////////////////////////////////////////////////////////////////////////////////////

	scene.addObject
	(
		std::make_unique<RealLight::Sphere>
		(
			glm::vec3{ 0, 200, 0 }, 100.0f, std::make_unique<RealLight::Emissive>(color3{ 2 })
			)
	);

}

int main(int, char**)
{
	const int width		= 1280;
	const int height	= 720;

	const int samples	= 1;

	const float fov = 40.0f;

	// Init
	RealLight::Renderer renderer;

	renderer.Init();
	renderer.CreateWindow(width, height);

	RealLight::Scene scene({ 0.7, 0.2, 0.8 }, { 1, 1, 1 });

	RealLight::Canvas canvas(width, height, renderer);

	Circles(scene);

	RealLight::Camera camera({ 0, 40, 48 }, { 0, 0, 0 }, { 0, 1, 0 }, fov, width / (float) height);
	//RealLight::Camera camera({ 0, 25, 0 }, { 0, 0, 0 }, { 0, 1, 0 }, fov, width / (float) height);
	//RealLight::Camera camera({ 13, 2, 3 }, { 0, 0, 0 }, { 0, 1, 0 }, fov, width / (float) height);

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