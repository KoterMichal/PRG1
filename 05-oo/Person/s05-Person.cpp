#include <iostream>
#include "Person.h"

auto main() -> int
{
    auto he = Mr("Adam", "Nowak");
    auto she = Mrs("Iza", "Kowalska");
    auto king = King("Jan", "Stary");
    auto queen = Queen("Eliza", "Adamska");

    std::cout << who_is_it(he);
    std::cout << who_is_it(she);
    std::cout << who_is_it(king);
    std::cout << who_is_it(queen);

    return 0;
}
