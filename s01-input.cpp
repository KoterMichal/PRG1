#include <iostream>
#include <string>


auto main() -> int
{
    std::cout << "What's your first  name? ";

    auto first_name = std::string{};
    std::getline(std::cin, first_name);

    std::cout << "What's your last name? ";

    auto last_name = std::string{};
    std::getline(std::cin,last_name);

    if (first_name.empty() && last_name.empty()) {
        std::cout << "OK, keep your secrets.\n";
    } else if (first_name.empty()) {
        std::cout << "It's you, " << last_name << "!\n";
    } else if (last_name.empty()) {
        std::cout << "Hi, " << first_name << "!\n";
    } else{
        std::cout << "Hello, " << first_name << " " << last_name << "!\n";
    }

    return 0;
}

