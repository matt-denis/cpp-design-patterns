#ifndef POINT_FACTORY_H
#define POINT_FACTORY_H

#include "Point.hpp"

class PointFactory
{
public:
    template <typename T>
    Point<T> create_cartesian(T x = 0, T y = 0);

    template <typename T>
    Point<T> create_polar(T r = 0, T theta = 0);

private:

};

#endif