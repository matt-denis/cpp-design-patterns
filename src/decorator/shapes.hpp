#ifndef SHAPES_H
#define SHAPES_H


#include <string>
#include <sstream>
#include <iostream>

class Shape
{
public:
    virtual std::string str() const = 0;
};

class Circle : public Shape
{
public:

    explicit Circle(const float radius) : radius{radius} {}

    std::string str() const override
    {
        std::ostringstream oss;
        oss << "A circle of radius " << radius <<std::endl;

        return oss.str();
    }

    void resize(float factor)
    {
        radius *= factor;
    }


private:
    float radius;
};

class Square : public Shape
{
public:
    explicit Square(const float side) : side{side} {}

    std::string str() const override
    {
        std::ostringstream oss;
        oss << "A square of side " << side << std::endl;

        return oss.str();
    }

    void resize(float factor)
    {
        side *= factor;
    }

private:
    float side;
};

#endif
