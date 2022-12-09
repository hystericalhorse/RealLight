#pragma once

#include "Math/Ray.h"
#include "Renderer/Material.h"

#include <memory>

namespace RealLight
{
	class Object
	{
	public:
		Object() = default;
		Object(std::unique_ptr<Material> material)
			: _material{ std::move(material) }
		{}

		virtual bool Hit(const Ray& ray, float min, float max, RaycastHit& hit) = 0;

		const Material* material() { return _material.get(); }

	protected:
		std::unique_ptr<Material> _material = nullptr;

	};
}