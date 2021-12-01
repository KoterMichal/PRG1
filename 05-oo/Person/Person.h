#ifndef Person_h
#define Person_h
#include <sstream>

struct Interface{
    Interface(){}
    virtual ~Interface(){}
    virtual auto to_string() const -> std::string = 0;
};

struct Person : Interface{
    std::string firstname;
    std::string lastname;

    Person(std::string firstn, std::string lastn)
        : firstname{firstn}
        , lastname{lastn}
    {}
    ~Person(){}

//    virtual auto to_string() const -> std::string = 0;
};

struct Mr : Person{
    Mr(std::string firstn, std::string lastn) : Person{firstn, lastn} {}
    ~Mr(){}

    auto to_string() const -> std::string;
};
auto Mr::to_string() const -> std::string{
    auto out = std::ostringstream();
    out << "Mr " << firstname << "\n";
    return out.str();
}

struct Mrs : Person{
    Mrs(std::string firstn, std::string lastn) : Person{firstn, lastn} {}
    ~Mrs(){}

    auto to_string() const -> std::string;
};
auto Mrs::to_string() const -> std::string{
    auto out = std::ostringstream();
    out << "Mrs " << firstname << "\n";
    return out.str();
}

struct King : Person{
    King(std::string firstn, std::string lastn) : Person{firstn, lastn} {}
    ~King(){}

    auto to_string() const -> std::string;
};
auto King::to_string() const -> std::string{
    auto out = std::ostringstream();
    out << "King " << firstname << "\n";
    return out.str();
}

struct Queen : Person{
    Queen(std::string firstn, std::string lastn) : Person{firstn, lastn} {}
    ~Queen(){}

    auto to_string() const -> std::string;
};
auto Queen::to_string() const -> std::string{
    auto out = std::ostringstream();
    out << "Queen " << firstname << "\n";
    return out.str();
}


auto who_is_it(Person const& per) -> std::string{
    return per.to_string();
}
#endif
