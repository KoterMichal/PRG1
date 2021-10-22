#ifndef Time_h
#define Time_h

#include <iostream>
#include <sstream>
#include <string>

namespace s03 {

struct Time{
    unsigned short hour{};
    unsigned short minute{};
    unsigned short second{};

    explicit Time(unsigned short hh, unsigned short mm, unsigned short ss)
        : hour{hh}
        , minute{mm}
        , second{ss}
    {
        if (hh > 23) {
            throw std::out_of_range{"hour value cannot exceed 23"};
        }
        if (mm >59) {
            throw std::out_of_range{"minute value cannot exceed 59"};
        }
        if (ss >59) {
            throw std::out_of_range{"second value cannot exceed 59"};
        }

    }

    auto to_string() const -> std::string;
    auto next_hour(unsigned short) -> void;
    auto next_minute(unsigned short) -> void;
    auto next_second(unsigned short) -> void;
};



}
#endif
