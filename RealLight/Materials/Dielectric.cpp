#include "Renderer/Material.h"

namespace RealLight
{
	bool Dielectric::Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const
	{
        attenuation = _albedo;

        glm::vec3 out_normal;
        float ni_over_nt;
        float cosine;

        if (glm::dot(ray.dir, hit.normal) > 0)
        {
            out_normal = -hit.normal;
            ni_over_nt = _index;
            cosine = _index * glm::dot(ray.dir, hit.normal) / ray.dir.length();
        }
        else
        {
            out_normal = hit.normal;
            ni_over_nt = 1.0f / _index;
            cosine = -glm::dot(ray.dir, hit.normal) / ray.dir.length();
        }

        glm::vec3 refracted;
        float reflectProbability = 1.0f;
        if (refract(ray.dir, out_normal, ni_over_nt, refracted))
        {
            reflectProbability = schlick(cosine, _index);
        }

        glm::vec3 reflected = reflect(glm::normalize(ray.dir), hit.normal);

        scattered = (randomBinary() < reflectProbability) ? Ray{ hit.point, reflected } : Ray{ hit.point, refracted };

        return true;
	}
}