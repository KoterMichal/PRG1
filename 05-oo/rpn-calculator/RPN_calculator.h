#ifdef RPN_calulator_h
#define RPN_calculator_h

#include <stack>

using my_stack= std::stack<double>;

struct Interface{
    virtual auto action(my_stack&) const -> void = 0;
    virtual ~Interface();
};

struct Element : Interface{
    double const value{0.0};
    Element(double);
    virtual ~Element();
    auto action(my_stack&) const -> coid override;
};

struct Print : Interface{
    virtual ~Print();
    auto action(my_stack&) const -> void override;
};

struct Addition : Interface{
    virtual ~Addition();
    auto action (my_stack&) const -> void override;
};


struct Calculator{
    my_stacl stack;

    auto push(*Interface) -> void;
    auto push(std::string) -> void;
    auto action() -> void;

    Calculator() = default;
    Calculator(my_stack);
    ~Calculator();
};


#endif
