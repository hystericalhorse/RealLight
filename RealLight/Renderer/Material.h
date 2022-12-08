#pragma once
#include "Math/Color.h"
#include "Math/Ray.h"

namespace RealLight
{
	class Material
	{
	public:
		virtual bool Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const = 0;
	};

	class Lambert : public Material
	{
	public:
		Lambert(const color3& albedo) : _albedo{ albedo } {}

		bool Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const override;

	protected:
		color3 _albedo{ 0 };
	};

	class Metal : public Material
	{
	public:
		Metal(const color3& albedo, const float& fuzz = 0) : _albedo{ albedo }, _fuzz{ fuzz } {}

		bool Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const override;

	protected:
		color3 _albedo{ 0 };
		float _fuzz;
	};
}