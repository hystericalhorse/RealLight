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

        return discriminant >= 0;
	}
}