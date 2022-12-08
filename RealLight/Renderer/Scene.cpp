#include "Scene.h"

#include "Math/Ray.h"
#include "Objects/Object.h"

namespace RealLight
{
	color3 Scene::Trace(const Ray& ray, float min, float max, RaycastHit& hit, int depth, float gradient)
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
                return hit.material->GetEmissive();
            }
        }
        else
        {
            glm::vec3 direction = glm::normalize(ray.dir);
            float t = (direction.y + 1) * gradient;
            return twerp(_upper, _lower, t);
        }

        return color3{ 0 };
	}

	void Scene::addObject(std::unique_ptr<Object> object)
	{
		_objects.push_back(std::move(object));
	}
}