#ifndef Item_h
#define Tiem_h
#include <sstream>

struct Creature{
    std::string name;
    int health_point;
    int max_health_point;

    Creature(std::string na, int hp)
        : name{na}
        , health_point{hp}
        , max_health_point{hp}
    {}
    ~Creature(){}

    auto to_string() const -> std::string;
};
auto Creature::to_string() const -> std::string{
    auto out = std::ostringstream();
    out << "Name: "<< name << " HP: " << health_point << "\n";
    return out.str();
}

struct Item{
    std::string name;
    int power;

    Item(std::string nam, int pow) : name{nam}, power{pow} {}
    virtual ~Item(){}

    virtual auto use_on(Creature&) -> void =0;
    virtual auto strenght() const -> int =0;
};

struct Weapon : Item{
    Weapon(std::string nam, int pow) : Item{nam, pow} {}
    virtual ~Weapon(){}

    auto use_on(Creature&) -> void override;
};
auto Weapon::use_on(Creature& creature) -> void{
    creature.health_point -= this->strenght();
    std::cout << creature.name << " took damage from " << this->name << ": -" << this->power << "\n";

}

struct Sword : Weapon{
    Sword(std::string nam, int pow) : Weapon{nam, pow} {}
    virtual ~Sword(){}

    auto strenght() const -> int override;
};
auto Sword::strenght() const -> int{
    return this->power;
}

struct Axe : Weapon{
    Axe(std::string nam, int pow) : Weapon{nam, pow} {}
    virtual ~Axe(){}

    auto strenght() const -> int override;
};
auto Axe::strenght() const -> int{
    return this->power;
}

struct Bow : Weapon{
    Bow(std::string nam, int pow) : Weapon{nam, pow} {}
    virtual ~Bow(){}

    auto strenght() const -> int override;
};
auto Bow::strenght() const -> int{
    return this->power;
}


struct Potion : Item{
    unsigned short amount_of_use;
    Potion(std::string nam, int pow, unsigned short aou) : Item{nam, pow} , amount_of_use{aou} {}
    virtual ~Potion(){}

    auto use_on(Creature&) -> void override;
};
auto Potion::use_on(Creature& creature) -> void{
    if(amount_of_use > 0){
        creature.health_point += this->strenght();
        if (creature.health_point > creature.max_health_point){
            creature.health_point = creature.max_health_point;
        }
        amount_of_use -= 1;
        std::cout << creature.name << " used " << this->name << ": +" << this->power <<"\n";
    } else {
        std::cout << "You can't use " << this->name << " anymore!\n";
    }
}

struct Health_potion : Potion{
    Health_potion(std::string nam, int pow, unsigned short aou = 2) : Potion{nam, pow, aou} {}
    virtual ~Health_potion(){}

    auto strenght() const -> int override;
};
auto Health_potion::strenght() const -> int {
    return this->power;
}

#endif
