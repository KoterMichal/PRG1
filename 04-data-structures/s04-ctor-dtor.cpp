#include <iostream>

struct Name{
    std::string tag;

    Name() = default;
    Name(std::string t):
        tag{t}
    {
        std::cout << "ctor\n";
    }

    ~Name()
    {
        std::cout << tag << " DESTRUCTION!\n";
    }
};

auto main() -> int
{
    auto sth= Name("something");

    return 0;
}
