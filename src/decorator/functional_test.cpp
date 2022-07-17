#include "functional_decorator.hpp"

int addition(int a, int b)
{
    std::cout << "Adding " << a << " + " << b << " = " << a + b << std::endl;

    return a + b;
}

int main()
{
    ::Logger([]() {std::cout << "Hello" << std::endl; }, "Hello Function")();

    auto add{[](int a, int b) {
        std::cout << "Adding " << a << " + " << b << " = " << a + b << std::endl;

        return a + b;
    }
    };

    auto adder = make_logger(addition, "Adder");
    int result = adder(1, 2);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
