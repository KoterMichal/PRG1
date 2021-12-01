#ifndef Person_h
#define Person_h
#include <sstream>

struct Person{
    std::string firstname;
    std::string lastname;

    Person(std::string firstn, std::string lastn)
        : firstname{firstn}
        , lastname{lastn}
    {}
    ~Person(){}

    virtual auto to_string() const -> std::string = 0;
};

struct Mr : Person{
    Mr(std::string firstn, std::string lastn) : Person{firstn, lastn} {}
    ~Mr(){}

    auto to_string() const -> std::string override;
};
auto Mr::to_string() const -> std::string{
    auto out = std::ostringstream();
    out << "Mr " << firstname << "\n";
    return out.str();
}

struct Mrs : Person{
    Mrs(std::string firstn, std::string lastn) : Person{firstn, lastn} {}
    ~Mrs(){}

    auto to_string() const -> std::string override;
};
auto Mrs::to_string() const -> std::string{
    auto out = std::ostringstream();
    out << "Mrs " << firstname << "\n";
    return out.str();
}

struct King : Person{
    King(std::string firstn, std::string lastn) : Person{firstn, lastn} {}
    ~King(){}

    auto to_string() const -> std::string override;
};
auto King::to_string() const -> std::string{
    auto out = std::ostringstream();
    out << "King " << firstname << "\n";
    return out.str();
}

struct Queen : Person{
    Queen(std::string firstn, std::string lastn) : Person{firstn, lastn} {}
    ~Queen(){}

    auto to_string() const -> std::string override;
};
auto Queen::to_string() const -> std::string{
    auto out = std::ostringstream();
    out << "Queen " << firstname << "\n";
    return out.str();
}


auto who_is_it(Person const& per) -> std::string{
    return per.to_string();
}

struct Greeting{
    Greeting(){}
    ~Greeting(){}

    virtual auto greet(Person const&) const -> std::string = 0;
};

struct Hello : Greeting{
    Hello(){}
    ~Hello(){}

    auto greet(Person const&) const -> std::string override;
};
auto Hello::greet(Person const& per) const-> std::string{
    auto out = std::ostringstream();
    out << "Hello " << per.to_string();
    return out.str();
}

struct Good_evening : Greeting{
    Good_evening(){}
    ~Good_evening(){}

    auto greet(Person const&) const -> std::string override;
};
auto Good_evening::greet(Person const& per) const-> std::string{
    auto out = std::ostringstream();
    out << "Good evening " << per.to_string();
    return out.str();
}

struct Farewell : Greeting{
    Farewell(){}
    ~Farewell(){}

    auto greet(Person const&) const -> std::string override;
};
auto Farewell::greet(Person const& per) const-> std::string{
    auto out = std::ostringstream();
    out << "Farewell " << per.to_string();
    return out.str();
}

#endif
