#pragma once

#include "Math/Color.h"

#include <vector>
#include <memory>

namespace RealLight
{
    class Object;
    struct Ray;
    struct RaycastHit;

    class Scene
    {
    public:
        Scene() = default;
        Scene(const color3& upper, const color3& lower, bool vertical_gradient = true)
            : _upper{ upper }, _lower{ lower }, gradient_dir{vertical_gradient}
        {}
        Scene(const color3& solid, bool vertical_gradient = true)
            : _upper{ solid }, _lower{ solid }, gradient_dir{ vertical_gradient }
        {}

        color3 Trace(const Ray& ray, float min, float max, RaycastHit& hit, int depth, float gradient = 0.5);
        void addObject(std::unique_ptr<Object> object);

    private:
        color3 _upper{ 0.0f, 0.0f, 0.6f };
        color3 _lower{ 0.7f, 0.0f, 0.7f };

        bool gradient_dir = true;

        std::vector <std::unique_ptr<Object>> _objects;

    };
}