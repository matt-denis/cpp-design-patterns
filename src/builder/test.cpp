#include <string>
#include <iostream>
class mcls
{
    std::string word;
public:
    mcls(const std::string& w) : word{w} {}
    const std::string& get_word() noexcept { return word; }
};

int main()
{
    auto cl{mcls{"hello"}};
    std::string ref = cl.get_word();
    ref = "abc";
    std::cout << cl.get_word() << std::endl;

    return 0;
}