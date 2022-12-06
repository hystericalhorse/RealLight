#include "Sphere.h"

namespace RealLight
{
	bool Sphere::Hit(const Ray& ray, float min, float max, RaycastHit& hit)
	{
        glm::vec3 oc = ray.origin - _center;
        float a = glm::dot(ray.dir, ray.dir);
        float b = 2 * glm::dot(ray.dir, oc);
        float c = glm::dot(oc, oc) - (_radius * _radius);
 
        float discriminant = (b * b) - (4 * a * c);

        if (discriminant >= 0)
        {
            float t1 = (-b - glm::sqrt(discriminant)) / (2 * a);
            float t2 = (-b + glm::sqrt(discriminant)) / (2 * a);

            if (t1 > min && t1 < max)
            {
                hit.distance = t1;

                hit.point = ray.get_point(t1);

                hit.normal = (hit.point - _center) / _radius;

                hit.material = std::move(_material).get();
                return true;
            }
            if (t2 > min && t2 < max)
            {
                hit.distance = t2;

                hit.point = ray.get_point(t2);

                hit.normal = (hit.point - _center) / _radius;

                hit.material = std::move(_material).get();
                return true;
            }
        }

        return false;
	}
}