#include "Scene.h"

#include "Math/Ray.h"
#include "Objects/Object.h"

namespace RealLight
{
	color3 Scene::Trace(const Ray& ray, float min, float max, RaycastHit& hit, int depth)
	{
        bool rayHit = false;

        float closest = max;

        for (auto& object : _objects)
        {
            if (object->Hit(ray, min, closest, hit))
            {
                rayHit = true;
                closest = hit.distance;
            }
        }

        if (rayHit)
        {
            Ray scattered;
            color3 attenuation;

            if (depth > 0 && hit.material->Scatter(ray, hit, attenuation, scattered))
            {
                return attenuation * Trace(scattered, min, max, hit, depth - 1);
            }
            else
            {
                return { 0, 0, 0 };
            }
        }
        else
        {
            glm::vec3 direction = glm::normalize(ray.dir);
            float t = (direction.y + 1) * 0.5f;
            return twerp(glm::vec3(0.5f, 0.7f, 1.0f), glm::vec3(1, 1, 1), t);
        }

        return color3{ 0 };
	}

	void Scene::addObject(std::unique_ptr<Object> object)
	{
		_objects.push_back(std::move(object));
	}
}