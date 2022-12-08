#pragma once

#include "Object.h"

namespace RealLight
{
	class Plane : public Object
	{
	public:
		Plane(const glm::vec3& center, const glm::vec3& normal, std::unique_ptr<Material> material)
			: Object{ std::move(material) }, _center{ center }, _normal{ normal }
		{}

		bool Hit(const Ray& ray, float min, float max, RaycastHit& hit) override;

	protected:
		glm::vec3 _center{ 0 };
		glm::vec3 _normal{ 0 };

	};
}