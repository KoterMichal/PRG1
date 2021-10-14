#include <iostream>
#include <string>

auto main(int argc, char* argr[]) -> int
{
    auto const password = std::string{argr[1]};
    auto input_password = std::string{};

    do{
        std::cout << "password: ";
        getline(std::cin, input_password);

    }while(password != input_password);

    return 0;
}
