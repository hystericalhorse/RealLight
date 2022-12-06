#include "Renderer/Material.h"

namespace RealLight
{
	bool Lambert::Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const
	{
		glm::vec3 direction = glm::normalize(hit.normal + spherePoint());

		scattered = { hit.point, direction };
		attenuation = _albedo;

		return true;
	}
}