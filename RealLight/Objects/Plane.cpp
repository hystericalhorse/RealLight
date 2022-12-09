#include "Plane.h"

namespace RealLight
{
	bool Plane::Hit(const Ray& ray, float min, float max, RaycastHit& hit)
	{
		float denominator = dot(ray.dir, _normal);
		if (absolute(denominator) < std::numeric_limits<float>::epsilon())
		{
			return false;
		}

		float t = glm::dot(_center - ray.origin, _normal) / denominator;
		if (t < 0)
		{
			return false;
		}

		if (t > min && t < max)
		{
			hit.distance = t;

			hit.point = ray.get_point(t);

			//hit.normal = hit.point - _center;
			hit.normal = _normal;

			hit.material = std::move(_material).get();

			return true;
		}

		return false;
	}
}