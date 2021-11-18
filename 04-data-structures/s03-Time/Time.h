#ifndef Test_h
#define Test_h

#include <iostream>
#include <sstream>
#include <string>


struct Time{
    int hour{};
    int minute{};
    int second{};

// time of day
    enum class Time_of_day {
        MORNING,
        AFTERNOON,
        EVENING,
        NIGHT
    };

// time- constructor
    Time() = default;
    explicit Time(int hh, int mm, int ss)
        : hour{hh}
        , minute{mm}
        , second{ss}
    {
        if (hh > 23 && hh < 0) {
            throw std::out_of_range{"hour value cannot exceed 23"};
        }
        if (mm > 59 && mm < 0) {
            throw std::out_of_range{"minute value cannot exceed 59"};
        }
        if (ss > 59 && ss < 0) {
            throw std::out_of_range{"second value cannot exceed 59"};
        }

    }

// time- functions
    auto to_string() const -> std::string;
    auto next_hour() -> void;
    auto next_minute() -> void;
    auto next_second() -> void;

// time of day- functions
    auto time_of_day() const -> Time_of_day;
    auto to_string(Time_of_day) -> std::string;

// arithmetic
    auto operator+ (Time const&) const -> Time;
    auto operator- (Time const&) const -> Time;
    auto operator< (Time const&) const -> bool;
    auto operator> (Time const&) const -> bool;
    auto operator== (Time const&) const -> bool;
    auto operator!= (Time const&) const -> bool;

// seconds to midnight
    auto count_seconds() const -> uint64_t;
    auto count_minutes() const -> uint64_t;
    auto time_to_midnight() const -> Time;
};



// time- functions
auto Time::to_string() const -> std::string
{
    auto out = std::ostringstream{};

    if (hour < 10){
        out << "0" << hour << ":";
    } else {
        out << hour << ":";
    }

    if (minute < 10){
        out << "0" << minute << ":";
    } else {
        out << minute << ":";
    }

    if (second < 10){
        out << "0" << second;
    } else {
        out << second;
    }

    return out.str();
}

auto Time::next_hour() -> void
{
    hour++;
    if (hour > 23){
        hour -= 24;
    }
}

auto Time::next_minute() -> void
{
    minute++;
    if (minute > 59){
        minute -= 60;
        next_hour();
    }
}

auto Time::next_second() -> void
{
    second++;
    if (second > 59){
        second -= 60;
        next_minute();
    }
}

// time of day- functions

auto Time::time_of_day() const -> Time_of_day
{
    if (hour > 4 && hour <10){
        return Time_of_day::MORNING;
    }else if(hour >9 && hour < 18){
        return Time_of_day::AFTERNOON;
    }else if(hour >16 && hour <23){
        return Time_of_day::EVENING;
    }else {
        return Time_of_day::NIGHT;
    }
}

auto Time::to_string(Time_of_day time_of_day) -> std::string
{
    switch(time_of_day){
        case Time_of_day::MORNING:
            return "rano";
            break;
        case Time_of_day::AFTERNOON:
            return "dzień";
            break;
        case Time_of_day::EVENING:
            return "wieczór";
            break;
        case Time_of_day::NIGHT:
            return "noc";
            break;
    }
    return "";
}

// arithmetic- functions

auto Time::operator+ (Time const& t) const -> Time
{
    auto result = Time{hour, minute, second};
    result.hour += t.hour;
    result.minute += t.minute;
    result.second += t.second;

    if (result.hour > 23){
        result.hour -= 24;
    }
    if (result.minute > 59){
        result.next_hour();
        result.minute -= 60;
    }
    if (result.second > 59){
        result.next_minute();
        result.second -= 60;
    }

    return result;
}

auto Time::operator- (Time const& t) const -> Time
{
    auto result = Time{hour, minute, second};
    result.hour -= t.hour;
    result.minute -= t.minute;
    result.second -= t.second;

    if (result.second < 0){
        result.minute -= 1;
        result.second += 60;
    }
    if (result.minute < 0){
        result.hour -= 1;
        result.minute += 60;
    }
    if (result.hour < 0){
        result.hour += 24;
    }

    return result;
}

auto Time::operator< (Time const& t) const -> bool
{
    if (hour < t.hour){
        return true;
    } else if (minute < t.minute && hour == t.hour){
        return true;
    } else if (second < t.second && minute == t.minute){
        return true;
    } else {
        return false;
    }
}

auto Time::operator> (Time const& t) const -> bool
{
    if (hour > t.hour){
        return true;
    } else if (minute > t.minute && hour == t.hour){
        return true;
    } else if (second > t.second && minute == t.minute){
        return true;
    } else {
        return false;
    }
}

auto Time::operator== (Time const& t) const -> bool
{
    if (hour == t.hour && minute == t.minute && second == t.second){
        return true;
    } else {
        return false;
    }
}

auto Time::operator!= (Time const& t) const -> bool
{
    if (hour != t.hour && minute != t.minute && second != t.second){
        return true;
    } else {
        return false;
    }
}

// seconds to midnight- functions
auto Time::count_seconds() const -> uint64_t
{
    return second + minute * 60 + hour * 3600;
}

auto Time::count_minutes() const -> uint64_t
{
    return minute + hour * 60;
}

auto Time::time_to_midnight() const -> Time
{
    auto current = Time{hour,minute,second};
    auto result = Time{23,59,59};
    result = result - current;
    result.next_second();
    return result;
}

#endif
