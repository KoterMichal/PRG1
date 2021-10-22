
#include <iostream>
#include "Time.h"

auto s03::Time::to_string() const -> std::string
{
    auto out = std::ostringstream{};
    out << hour << ":" << minute << ":" << second;
    return out.str();
}

auto s03::Time::next_hour(unsigned short hh = 1) -> void
{
    hour += hh;
    if (hour > 23){
        hour -= 24;
    }
}

auto s03::Time::next_minute(unsigned short mm = 1) -> void
{
    minute += mm;
    if (minute > 59){
        minute -= 60;
        next_hour();
    }
}

auto s03::Time::next_second(unsigned short ss = 1) -> void
{
    second += ss;
    if (second > 59){
        second -= 60;
        next_minute();
    }
}

auto main() -> int{
    s03::Time time(23, 59, 59);

    std::cout << time.to_string() << "\n";
    time.next_second();
    std::cout << time.to_string() << "\n";
    time.next_minute();
    std::cout << time.to_string() << "\n";
    time.next_hour();
    std::cout << time.to_string() << "\n";

    return 0;
}
