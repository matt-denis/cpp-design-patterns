#ifndef DYNAMIC_DECORATOR_H
#define DYNAMIC_DECORATOR_H

#include <cstdint>

#include "shapes.hpp"

class ColoredShape : public Shape
{
public:
    ColoredShape(const Shape& shape, const std::string& color)
        : shape{shape}, color{color} {}

    std::string str() const override
    {
        std::ostringstream oss;
        oss << shape.str() << " has the color " << color << std::endl;

        return oss.str();
    }

private:
    const Shape& shape;
    const std::string color;
};

class TransparentShape : public Shape
{
public:
    TransparentShape(const Shape& shape, const uint8_t transparency)
        : shape{shape}, transparency{transparency} {}

    std::string str() const override
    {
        std::ostringstream oss;
        oss << shape.str() << " has " << static_cast<float>(transparency) / 255.f*100.f
            << "% transparency" << std::endl;

        return oss.str();
    }

private:
    const Shape& shape;
    uint8_t transparency;
};

#endif
