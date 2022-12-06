#pragma once

#include <glm.hpp>

namespace RealLight
{
	class Material;

	struct Ray
	{
		Ray() = default;
		Ray(const glm::vec3& origin, const glm::vec3& dir)
		: origin {origin}, dir{dir}
		{}

		glm::vec3 get_point(float dis) const { return origin + (dir * dis); }

		glm::vec3 origin{ 0 };
		glm::vec3 dir{ 0 };
	};

	struct RaycastHit
	{
		float distance = 0.0f;

		glm::vec3 point{ 0 };
		glm::vec3 normal{ 0 };

		Material* material = nullptr;
	};
}