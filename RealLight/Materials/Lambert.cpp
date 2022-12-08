#include "Renderer/Material.h"

namespace RealLight
{
	bool Lambert::Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const
	{
		glm::vec3 target = hit.point + hit.normal + spherePoint();
		glm::vec3 direction = glm::normalize(target - hit.point);

		scattered = { hit.point, direction };
		attenuation = _albedo;

		return true;
	}
}