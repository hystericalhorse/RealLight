#pragma once

#include "Math/MathUtils.h"
#include "Math/Ray.h"

namespace RealLight
{
	class Camera
	{
	public:
		Camera(const glm::vec3& eye, const glm::vec3& target, const glm::vec3& up, float fov, float aspectRatio);

		void LookAt(const glm::vec3& eye, const glm::vec3& target, const glm::vec3& up);

		Ray PointToRay(const glm::vec2& point) const;

	protected:
		void CalculateViewPlane();

		glm::vec3 _eye{ 0 };

		glm::vec3 _right{ 0 };
		glm::vec3 _up{ 0 };
		glm::vec3 _forward{ 0 };

		glm::vec3 _lowerleft{ 0 };
		glm::vec3 _horizontal{ 0 };
		glm::vec3 _vertical{ 0 };

		float _fov = 0.0f;
		float _aspect = 0.0f; // screen-width / screen-height

	};
}