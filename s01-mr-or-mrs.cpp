#include <iostream>
#include <string>

auto main() -> int
{
    std::cout << "what's your name?: ";

    auto name = std::string{};
    std::getline(std::cin, name);

    auto last_letter = name.back();

    if (last_letter == 'a'){
        std::cout << "Pani " << name << "\n";
    } else {
        std::cout << "Pan " << name << "\n";
    }

    return 0;
}
