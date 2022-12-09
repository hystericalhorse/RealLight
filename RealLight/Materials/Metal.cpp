#include "Renderer/Material.h"

namespace RealLight
{
	bool Metal::Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const
	{
		glm::vec3 reflected = reflect(glm::normalize(ray.dir), hit.normal);

		scattered = { hit.point, reflected + spherePoint() * _fuzz};
		attenuation = _albedo;

		return dot(hit.normal, scattered.dir) > 0;
	}
}