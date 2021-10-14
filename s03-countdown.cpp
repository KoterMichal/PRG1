#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    auto const number = std::stoi(std::string{argv[1]});

    if(number > 0){
        for(int i = number; i != 0; i--){
            std::cout << i << "\n";
        }
    } else if(number < 0){
        for(int i = number; i != 0; i++){
            std::cout << i << "\n";
        }
    } else
        std::cout << number << "\n";

    return 0;
}
