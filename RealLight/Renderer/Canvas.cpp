#include "Canvas.h"
#include "Renderer.h"

namespace RealLight
{
    Canvas::Canvas(int width, int height, const Renderer& renderer)
        : _width {width}, _height {height}
    {
        _texture = SDL_CreateTexture
        (
            renderer._renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height
        );

        _buffer.resize(width * height);
    }

    Canvas::~Canvas()
    {
        if (_texture)
            SDL_DestroyTexture(_texture);
    }

    void Canvas::Update()
    {
        SDL_UpdateTexture(_texture, nullptr, _buffer.data(), _width * sizeof(rgba_t));
    }

    void Canvas::Draw(const Renderer& renderer)
    {
        SDL_RenderCopy(renderer._renderer, _texture, nullptr, nullptr);
    }

    void Canvas::Clear(const color4& color)
    {
        rgba_t rgba = ColorToRGBA(color);
        std::fill(_buffer.begin(), _buffer.end(), rgba);
    }

    void Canvas::DrawPoint(const glm::ivec2& point, const color4& color)
    {
        _buffer[point.x + (point.y * _width)] = ColorToRGBA(color);
    }
}