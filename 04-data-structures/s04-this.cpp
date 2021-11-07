#include <iostream>

struct Dog
{
    std::string name;

    Dog(std::string n)
        : name{n}
    {}

    auto to_string() -> std::string;
};

auto Dog::to_string() -> std::string
{
    return (this->name);
}

auto main() -> int
{
    auto dog1 = Dog("Reksio");
    std::cout << dog1.to_string() << "\n";
    std::cout << &dog1.name << "\n";
    return 0;
}
