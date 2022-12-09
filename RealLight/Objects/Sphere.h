#pragma once

#include "Object.h"
#include <memory>

namespace RealLight
{
	class Sphere : public Object
	{
	public:
		Sphere() = default;
		Sphere(const glm::vec3& center, float radius, std::unique_ptr<Material> material)
			: Object{ std::move(material) }, _center{ center }, _radius{ radius }
		{}

		bool Hit(const Ray& ray, float min, float max, RaycastHit& hit) override;

	protected:
		glm::vec3 _center{ 0 };
		float _radius = 0;


	};
}