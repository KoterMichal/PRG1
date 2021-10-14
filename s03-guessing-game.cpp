#include <iostream>
#include <random>

auto main() -> int
{
    std::random_device rd;
    std::uniform_int_distribution<int> d100 (1, 100);

    auto const random_number = d100(rd);
    auto input_number = std::string{};
    int guess_number;

    do{
        std::cout << "guess: ";

        getline(std::cin, input_number);
        guess_number = std::stoi(input_number);

        if(random_number > guess_number){
            std::cout << "number too small! \n";
        } else if(random_number < guess_number){
            std::cout << "number too big! \n";
        }
    }while(random_number != guess_number);

    std::cout << "just right! \n";

    return 0;
}
