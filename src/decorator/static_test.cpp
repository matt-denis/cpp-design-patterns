#include "static_decorator.hpp"

int main()
{
    ColoredShape<TransparentShape<Square>> sq{"red", 51, 5};

    std::cout << sq.str() << std::endl;

    return 0;
}
