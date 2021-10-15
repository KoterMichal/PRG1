#include <iostream>

auto main(int argc, char* argv[]) -> int
{
    auto const buttles = std::stoi(argv[1]);

    for(int i = buttles; i > 1; i--){
        std::cout << i << " bottles of beer on the wall, "
                  << i << " bottles of beer. \n"
                  << "Take one down, pass it around, ";
    }
    std::cout << "1 battles of beer on the wall, 1 bottle of beer. \n"
              << "Take one down, pass it around, 0 bottle of beer on th wall \n"
              << "No more buttles of beer on the wall, no more bottles of beer. \n"
              << "Go to the store and buy some more, "
              << buttles << " bottles of beer on the wall... \n";

    return 0;
}
