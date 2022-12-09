#pragma once

#include <glm.hpp>
#include <glm/gtx/norm.hpp>
#include <cstdlib>
#include <algorithm>


/// <summary>
/// returns a random decimal between 0 and 1.
/// </summary>
inline float randomDecimal()
{
	return (float) rand() / RAND_MAX;
}

/// <summary>
/// returns a random number between the min and max.
/// </summary>
inline float randomf(float max, float min = 0)
{
	if (min > max) std::swap(min, max);

	return min + (max - min) * randomDecimal();
}

/// <summary>
/// returns a random number between the min and max.
/// </summary>
inline int randomBinary()
{
	return rand() % 2;
}

/// <summary>
/// interpolation between x and y using t.
/// </summary>
template<typename T>
inline T twerp(T x, T y, float t)
{
	return (x * (1.0f - t)) + (y * (t));
}

/// <summary>
/// returns a random point within a unit sphere
/// </summary>
inline glm::vec3 spherePoint()
{
    glm::vec3 point;

    do
    {
        point = glm::vec3{randomf(-1, 1), randomf(-1, 1), randomf(-1, 1) };
    }
    while (glm::length2(point) >= 1);

    return point;
}

/// <summary>
/// returns the absolute value of a float
/// </summary>
inline float absolute(float f)
{
    return (f < 0) ? -f : f;
}

/// <summary>
/// returns the dot product of two vectors
/// </summary>
inline float dot(const glm::vec3& v, const glm::vec3& w)
{
    return (v.x * w.x) + (v.y * w.y) + (v.z * w.z);
}

/// <summary>
/// returns the reflection of vector v
/// </summary>
inline glm::vec3 reflect(const glm::vec3& v, const glm::vec3& n)
{
    return v - ((n * dot(n, v)) * 2.0f);
}

/// <summary>
/// calculate the refraction of vector v
/// </summary>
inline bool refract(const glm::vec3& v, const glm::vec3& n, float index, glm::vec3& refracted)
{
    glm::vec3 nv = glm::normalize(v);
    float dt = dot(nv, n);
    float discriminant = 1 - (index * index) * (1 - dt * dt);
    if (discriminant > 0)
    {
        refracted = index * (nv - (n * dt)) - (n * std::sqrt(discriminant));
        return true;
    }

    return false;
}

/// <summary>
/// calculate probability of reflection for index i
/// </summary>
inline float schlick(float cosine, float i)
{
    float r0 = (1.0f - i) / (1 + i);
    r0 = r0 * r0;

    return r0 + (1.0f - r0) * (float)std::pow((1.0f - cosine), 5);
}