#include <iostream>
#include "Item.h"

auto main() -> int
{
    auto gnoll = Creature{"Alkin", 20};
    auto sword = Sword{"sword", 6};
    auto axe = Axe{"axe", 9};
    auto bow = Bow{"bow", 4};
    auto hp_potion = Health_potion{"health potion", 5};

    std::cout << gnoll.to_string() << "\n";
    sword.use_on(gnoll);
    std::cout << gnoll.to_string() << "\n";
    axe.use_on(gnoll);
    std::cout << gnoll.to_string() << "\n";
    bow.use_on(gnoll);
    std::cout << gnoll.to_string() << "\n";
    hp_potion.use_on(gnoll);
    std::cout << gnoll.to_string() << "\n";
    hp_potion.use_on(gnoll);
    std::cout << gnoll.to_string() << "\n";
    hp_potion.use_on(gnoll);
    std::cout << gnoll.to_string() << "\n";
    return 0;
}
