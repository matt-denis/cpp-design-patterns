#include "PointFactory.hpp"

template <typename T>
Point<T> PointFactory::create_cartesian(T x = 0, T y = 0)
{
    return {x, y};
}

template <typename T>
Point<T> PointFactory::create_polar(T r = 0, T theta = 0)
{
    return {r, theta};
}

