#include <iostream>
#include <stack>
#include <RPN_calculator.h>


static auto pop_top(std::stack<double>& stack) -> double{
    if (stack.empty()) {
        throw std::logic_error{"empty stack"};
    }
    auto element = std::move(stack.top());
    stack.pop();
    return element;
}

Interface::~Interface()
{}

Element::Element(double const v) : value{v}
{}

auto Element::action(my_stack& stack) const -> void{
    stack.push(value);
}

auto Print::action(my_stack& stack) const -> void{
    std::cout << stack.top() << "\n";
}

auto Addition::action(my_stack& stack) const -> void{
    if (stack.size() < 2){
         throw std::logic_error{"not enough operands of +"};
    }
    auto b = pop_top(stack);
    auto a = pop_top(stack);
    stack.push(a+b);
}

Calculator::Calculator(my_stack s) : stack{std::move(s)}
{}

Calculator::~Calculator()
{}

auto Calculator::push(*Element op) -> void{
    ops.push(std::move(op));
}

//auto Calculator::push(std::sting) -> void

auto Calculator::action() -> void{
    while (!ops.empty()){
        auto op = std::move(ops.front());
        ops.pop();
        op -> action(stack);
    }
}

auto main(int argc,char* argv[]) -> int
{
    auto calculator = Calculator{};

    for (int i=1; i < std::size_of(*argv[]); i++){
        try{
            if (i == 'p'){
                calculator.push(*Print);
            } else if (i == '+'){
                calculator.push(*Addition);
            } else {
                calculator.push(*Element(std::stod(i)));
            }
        } catch (std::logic_error const& e) {
            std::cerr << "error: " << i << ": " << e.what() << "\n";
        }

        try{
            calculator.action();
        } catch {
            std::cerr << "error: during action: " << e.what() << "\n";
        }
    }
    return 0;
}
