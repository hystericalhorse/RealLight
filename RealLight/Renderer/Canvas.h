#pragma once

#include "../Math/Color.h"

#include <SDL.h>
#include <vector>

namespace RealLight
{
    class Renderer;

	class Canvas
	{
    public:
        Canvas(int width, int height, const Renderer& renderer);
        ~Canvas();

        void Update();
        void Draw(const Renderer& renderer);

        void Clear(const color4& color);
        void DrawPoint(const glm::ivec2& point, const color4& color);

        inline int GetWidth() const { return _width; }
        inline int GetHeight() const { return _height; }

        friend class Renderer;

    protected:
        SDL_Texture* _texture{ nullptr };
        std::vector<rgba_t> _buffer;

        int _width = 0;
        int _height = 0;
	};
}