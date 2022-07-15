#include "Point.hpp"
#include <tuple>
#include <cmath>
#include <iostream> // remove after main function compilation test

template <typename T>
Point<T>::Point(T coord_1, T coord_2, Point<T>::CoordinateSystem coordinate_system)
    : coordinate_system{coordinate_system}
{
    coordinates._x = coord_1;
    coordinates._y = coord_2;
}

template <typename T>
Point<T>::Point(const std::pair<T, T>& coords, CoordinateSystem coordinate_system)
    : coordinate_system{coordinate_system}
{
    std::tie(this->coordinates._x, this->coordinates._y) = coords;
}

template <typename T>
constexpr bool Point<T>::is_cartesian() noexcept
{
    return coordinate_system == CoordinateSystem::CARTESIAN;
}

template <typename T>
constexpr bool Point<T>::is_polar() noexcept
{
    return coordinate_system == CoordinateSystem::POLAR;
}

/**
 * Additions on the cartesian or polar plane depending on coordinates.
 * To add polars on the cartesian plane, convert to cartesian first
 */
template <typename T>
template <typename E>
Point<std::common_type_t<T, E>> Point<T>::operator+(const Point<E>& addend)
{
    addend.convert_to(this->coordinate_system);
    return {this->coordinates._x + addend.coordinates._x, this->coordinates._y + addend.coordinates._y};
}

template <typename T>
template <typename E>
Point<std::common_type_t<T, E>> Point<T>::operator-(const Point<E>& subtrahend)
{
    subtrahend.convert_to(this->coordinate_system);
    return {this->coordinates._x - subtrahend.coordinates._x, this->coordinates._y - subtrahend.coordinates._y};
}

template <typename T>
template <typename E>
Point<std::common_type_t<T, E>> Point<T>::operator*(E scalar)
{
    if (is_cartesian()) return {scalar * coordinates._x, scalar * coordinates._y};
    else return {scalar * coordinates._r, coordinates._theta};
}

template <typename E1, typename E2>
inline Point<std::common_type_t<E1, E2>> operator*(E1 scalar, const Point<E2>& point)
{
    return point * scalar;
}

template <typename T>
template<typename E>
std::common_type<T, E> Point<T>::dot(const Point<E>& factor)
{
    // TODO: need to implement formula for dotting in polars
    return this->coordinates._x*factor.coordinates._x + this->coordinates._y*factor.coordinates._y;
}

template <typename T>
std::pair<T, T> Point<T>::get_coordinates()
{
    if (is_cartesian()) return cartesian_coordinates();
    else return polar_coordinates();
}

template <typename T>
void Point<T>::convert_to_cartesian()
{
    if (is_cartesian()) return;

    std::tie(coordinates._x, coordinates._y) = convert_to_cartesian({coordinates._r, coordinates._theta});

    coordinate_system = CoordinateSystem::CARTESIAN;
}

template <typename T>
std::pair<T, T> Point<T>::convert_to_cartesian(const std::pair<T, T>& polar_coords)
{
    return {polar_coords.first * std::cos(polar_coords.second), polar_coords.first * std::sin(polar_coords.second)};
}

template <typename T>
void Point<T>::convert_to_polar()
{
    if (is_polar()) return;

    std::tie(coordinates._r, coordinates._theta) = convert_to_polar({coordinates._x, coordinates._y});

    coordinate_system = CoordinateSystem::POLAR;
}

template <typename T>
std::pair<T, T> Point<T>::convert_to_polar(const std::pair<T, T>& cartesian_coords)
{
    T theta{cartesian_coords.first == 0 ? M_PI_2 : cartesian_coords.second / cartesian_coords.second};
    return {std::sqrt(coordinates._x*coordinates._x + coordinates._y*coordinates._y),
            cartesian_coords.first == 0 ? M_PI_2 : std::atan(cartesian_coords.second / cartesian_coords.first)};
}

template <typename T>
void Point<T>::convert_to(CoordinateSystem coordinate_system)
{
    switch(coordinate_system)
    {
        case CoordinateSystem::CARTESIAN:
            convert_to_cartesian();
        case CoordinateSystem::POLAR:
            convert_to_polar();
    }
}

int main()
{
    std::cout << "Hello World" << std::endl;
    return 0;
}
