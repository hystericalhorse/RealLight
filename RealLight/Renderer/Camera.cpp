#include "Camera.h"

namespace RealLight
{
	Camera::Camera(const glm::vec3& eye, const glm::vec3& target, const glm::vec3& up, float fov, float aspectRatio)
		: _fov {fov}, _aspect {aspectRatio}
	{
		LookAt(eye, target, up);
	}

	void Camera::LookAt(const glm::vec3& eye, const glm::vec3& target, const glm::vec3& up)
	{
		_eye = eye;

		_forward = glm::normalize(eye - target);
		_right = glm::normalize(glm::cross(up, _forward));
		_up = glm::cross(_forward, _right);

		CalculateViewPlane();
	}

	Ray Camera::PointToRay(const glm::vec2& point) const
	{
		Ray ray;
		ray.origin = _eye;

		ray.dir = _lowerleft + (point.x * _horizontal) + (point.y * _vertical) - _eye;

		return ray;
	}

	void Camera::CalculateViewPlane()
	{
		float theta = glm::radians(_fov);

		float halfHeight = tan(theta * 0.5f);
		float halfWidth = halfHeight * _aspect;
		float height = halfHeight * 2;
		float width = halfWidth * 2;

		_horizontal = width * _right;
		_vertical = height * _up;
		_lowerleft = _eye - (_horizontal * 0.5f) - (_vertical * 0.5f) - _forward;
	}
}