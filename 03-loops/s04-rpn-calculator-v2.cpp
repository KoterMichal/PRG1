#include <iostream>
#include <cmath>
#include <math.h>

auto main(int argc,char* argv[]) -> int
{
    double x = 0;
    double y = 0;
    std::string input;
    for(int i = 1; i < argc; i++)
    {
        input = std::string(argv[i]);
        if(input == "+"){
            y = x + y;
        } else if (input == "-"){
            y = x - y;
        } else if (input == "*"){
            y = x * y;
        } else if (input == "**"){
            y= std::pow(x, y);
        } else if (input == "/"){
            y = x / y;
        } else if (input == "/""/"){
            y = std::floor(x) / std::floor(y);
        } else if (input == "%"){
            y = std::fmod(x, y);
        } else if (input == "sqrt"){
            y = std::sqrt(y);
        } else if (input == "hypot") {
            y = std::hypot(x, y);
        } else {
            x = y;
            y = std::stof(argv[i]);
        }


    }
    std::cout << y << "\n";
    return 0;
}
