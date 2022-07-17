#ifndef STATIC_DECORATOR_H
#define STATIC_DECORATOR_H

#include <type_traits>

#include "shapes.hpp"

template <typename T>
class ColoredShape : public T
{
    static_assert(std::is_base_of<::Shape, T>::value, "Template argument must be a Shape");
public:
    template<typename... Args>
    ColoredShape(const std::string& color, Args... args)
        : T(std::forward<Args>(args)...), color{color} {}

    std::string str() const override
    {
        std::ostringstream oss;
        oss << T::str() << " has the color " << color << std::endl;

        return oss.str();
    }

private:
    std::string color;
};

template <typename T>
class TransparentShape : public T
{
    static_assert(std::is_base_of<::Shape, T>::value, "Template argument must be a Shape");

public:
    template <typename... Args>
    TransparentShape(const uint8_t transparency, Args... args)
        : T(std::forward<Args>(args)...), transparency{transparency} {}

    std::string str() const override
    {
        std::ostringstream oss;
        oss << T::str() << " has " << static_cast<float>(transparency) / 255.f*100.f
            << "% transparency" << std::endl;

        return oss.str();
    }

private:
    uint8_t transparency;
};

#endif
