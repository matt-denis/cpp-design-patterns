#ifndef POINT_H
#define POINT_H

#include <utility>
#include <type_traits>
#include <stdexcept>

// TODO: abstract coordinate system as another pluggable class. Point has-a coordinate system.

template <typename T>
struct Point
{
    template <typename E1, typename E2>
    friend Point<std::common_type_t<E1, E2>> operator*(E1 scalar, const Point<E2>&);

public:

    typedef T number_field;

    template <typename E>
    Point<std::common_type_t<number_field, E>> operator+(const Point<E>& addend);

    template <typename E>
    Point<std::common_type_t<number_field, E>> operator-(const Point<E>& subtrahend);

    template <typename E>
    Point<std::common_type_t<number_field, E>> operator*(E scalar);

    template <typename E>
    std::common_type<T, E> dot(const Point<E>& factor);

    std::pair<number_field, number_field> get_coordinates();

    constexpr bool is_cartesian() noexcept;

    constexpr bool is_polar() noexcept;

    void convert_to_cartesian();

    void convert_to_polar();



private:

    enum class CoordinateSystem { CARTESIAN, POLAR };

    union Coordinates
    {
        // TODO: convert structs to pairs
        struct {
            number_field _x, _y;
        };

        struct {
            number_field _r, _theta;
        };
    };

    Coordinates coordinates;
    CoordinateSystem coordinate_system;

    Point(number_field coord_1, number_field coord_2, CoordinateSystem coordinate_system);

    Point(const std::pair<number_field, number_field>& coordinates, CoordinateSystem coordinate_system);

    constexpr std::pair<number_field, number_field> cartesian_coordinates() noexcept;

    constexpr std::pair<number_field, number_field> polar_coordinates() noexcept;

    void convert_to(CoordinateSystem coordinate_system);

    std::pair<number_field, number_field> convert_to_cartesian(const std::pair<number_field, number_field>&);

    std::pair<number_field, number_field> convert_to_polar(const std::pair<number_field, number_field>&);

};

#endif
