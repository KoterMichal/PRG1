#include <iostream>
#include <cmath>
#include <math.h>

auto add(double a, double b) -> double
{
    return a + b;
}

auto sub(double a, double b) -> double
{
    return a - b;
}

auto mul(double a, double b) -> double
{
    return a * b;
}

auto div(double a, double b) -> double
{
    return a / b;
}

auto div_int(double a, double b) -> double
{
    return std::floor(a) / std::floor(b);
}

auto mod(double a, double b) -> double
{
    return std::fmod(a,b);
}

auto power(double a, double b) -> double
{
    return std::pow(a,b);
}

auto square_root(double a) -> double
{
    return std::sqrt(a);
}

auto hypotenuse(double a, double b) -> double
{
    return std::hypot(a, b);
}

auto main(int argc,char* argv[]) -> int
{
    double x = 0;
    double y = 0;

    for(int i = 1; i < argc; i++)
    {
        if(argv[i][0] == '+'){
            y = add(x,y);
        } else if (argv[i][0] == '-'){
            y = sub(x,y);
        } else if (argv[i][0] == '*'){
            if (argv[i][1] == '*'){
                y= power(x, y);
            } else {
                y = mul(x, y);
            }
        } else if (argv[i][0] == '/'){
            if (argv[i][1] == '/'){
                y = div_int(x, y);
            } else {
                y = div(x, y);
            }
        } else if (argv[i][0] == '%'){
            y = mod(x, y);
        } else if (argv[i][0] == 's' && argv[i][1] == 'q' && argv[i][2] == 'r' && argv[i][3] == 't'){
            y = square_root(y);
        } else  if (argv[i][0] == 'h' && argv[i][1] == 'y' && argv[i][2] == 'p' && argv[i][3] == 'o' && argv[i][4] == 't') {
            y = hypotenuse(x, y);
        } else {
            x = y;
            y = std::stof(argv[i]);
        }


    }
    std::cout << y << "\n";
    return 0;
}
