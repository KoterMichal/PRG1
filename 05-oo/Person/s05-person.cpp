#include <iostream>
#include "Person.h"

auto main() -> int
{
    auto he = Mr("Adam", "Nowak");
    auto she = Mrs("Iza", "Kowalska");
    auto king = King("Jan", "Stary");
    auto queen = Queen("Eliza", "Adamska");
    auto hello = Hello();
    auto goodevening = Good_evening();
    auto farewell = Farewell();

    std::cout << "who is it:\n";
    std::cout << who_is_it(he);
    std::cout << who_is_it(she);
    std::cout << who_is_it(king);
    std::cout << who_is_it(queen);
    std::cout << "\n";

    std::cout << "hello:\n";
    std::cout << hello.greet(he);
    std::cout << hello.greet(she);
    std::cout << hello.greet(king);
    std::cout << hello.greet(queen);
    std::cout << "\n";

    std::cout << "good evening:\n";
    std::cout << goodevening.greet(he);
    std::cout << goodevening.greet(she);
    std::cout << goodevening.greet(king);
    std::cout << goodevening.greet(queen);
    std::cout << "\n";

    std::cout << "farewell:\n";
    std::cout << farewell.greet(he);
    std::cout << farewell.greet(she);
    std::cout << farewell.greet(king);
    std::cout << farewell.greet(queen);

    return 0;
}
