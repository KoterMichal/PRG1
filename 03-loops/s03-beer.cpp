#include <iostream>

auto main(int argc, char* argv[]) -> int
{
    auto const buttles = std::stoi(argv[1]);

    for(int i = buttles; i > 0; i--){
        if(i > 2){
            std::cout << i << " bottles of beer on the wall, "
                      << i << " bottles of beer. \n"
                      << "Take one down, pass it around, "
                      << i-1 << " bottles of beer on the wall. \n \n";
        } else if(i == 2){
            std::cout << i << " bottles of beer on the wall, "
                      << i << " bottles of beer. \n"
                      << "Take one down, pass it around, "
                      << i-1 << " bottle of beer on the wall. \n \n";
        } else{
            std::cout << i << " battle of beer on the wall, "
                      << i << " bottle of beer. \n"
                      << "Take one down, pass it around, "
                      << "No more buttles of beer on the wall \n\n";
        }
    }

    std::cout << "No more buttles of beer on the wall, "
              << "no more bottles of beer. \n"
              << "Got to the store and buy some more, "
              << buttles << " botteles of beer on the wall... \n";

    return 0;
}
