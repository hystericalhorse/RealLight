#pragma once
#include "Math/Color.h"
#include "Math/Ray.h"

namespace RealLight
{
	class Material
	{
	public:
		virtual bool Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const = 0;
		virtual color3 GetEmissive() { return { 0, 0, 0 }; }
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

	class Emissive : public Material
	{
	public:
		Emissive(const color3& albedo) : _albedo{ albedo } {}

		bool Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const override
		{
			return false;
		}

		color3 GetEmissive() override { return _albedo; };

	protected:
		color3 _albedo{ 0 };
	};

	class Dielectric : public Material
	{
	public:
		Dielectric(const color3& albedo = color3{ 0 }, const float& index = 1) : _albedo{ albedo }, _index{ index } {}

		bool Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const override;

	protected:
		color3 _albedo{ 0 };
		float _index;
	};
}