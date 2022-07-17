#include "dynamic_decorator.hpp"

int main()
{
    ::Square square{3};
    ::TransparentShape demiSquare{square, 85};
    std::cout << demiSquare.str() << std::endl;

    ::TransparentShape myCircle{
        ::ColoredShape{
            ::Circle{23}, "green"
        }, 64
    };
    std::cout << myCircle.str() << std::endl;

    return 0;
}
