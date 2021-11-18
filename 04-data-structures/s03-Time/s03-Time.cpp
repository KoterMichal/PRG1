#include <iostream>
#include "Time.h"


auto main() -> int
{
// time
    auto time = s24569::Time{23, 59, 59};
    std::cout << "to_string()\n" << time.to_string() << "\n";

    time = s24569::Time{23,59,59};
    std::cout << "next_hour()\n" << time.to_string() << " -> ";
    time.next_hour();
    std::cout << time.to_string() << "\n";

    time = s24569::Time{23,59,59};
    std::cout << "next_minute()\n" << time.to_string() << " -> ";
    time.next_minute();
    std::cout << time.to_string() << "\n";

    time = s24569::Time{23,59,59};
    std::cout << "next_second()\n" << time.to_string() << " -> ";
    time.next_second();
    std::cout << time.to_string() << "\n";

// time of day
    time = s24569::Time{23,59,59};
    std::cout << "to_sring(time_of_day())\n" << time.to_string() << " -> "
              << time.to_string(time.time_of_day()) << "\n";

// arithmetic
    time = s24569::Time{20,10,30};
    auto time2 = s24569::Time{4,36,23};
    auto time3 = time + time2;

    std::cout << "operator+\n"
              << time.to_string() << " + " << time2.to_string()
              << " = " << time3.to_string() << "\n";

    time3 = time - time2;
    std::cout << "operator-\n"
              << time.to_string() << " - " << time2.to_string()
              << " = " << time3.to_string() << "\n";

    time = s24569::Time{20,10,30};
    time2 = s24569::Time{4,36,23};
    std::cout << "operator<\n"
              << time.to_string() << " < " << time2.to_string() << " -> ";
    if (time < time2){
        std::cout << "TRUE\n";
    } else {
        std::cout << "FASLE\n";
    }

    std::cout << "operator>\n"
              << time.to_string() << " > " << time2.to_string() << " -> ";
    if (time > time2){
        std::cout << "TRUE\n";
    } else {
        std::cout << "FALSE\n";
    }
    }
}

auto s24569::Time::to_string(Time_of_day time_of_day) -> std::string
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

auto s24569::Time::operator+ (Time const& t) const -> Time
{
    auto result = s24569::Time{hour, minute, second};
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

auto s24569::Time::operator- (Time const& t) const -> Time
{
    auto result = s24569::Time{hour, minute, second};
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

auto s24569::Time::operator< (Time const& t) const -> bool
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

auto s24569::Time::operator> (Time const& t) const -> bool
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

auto s24569::Time::operator== (Time const& t) const -> bool
{
    if (hour == t.hour && minute == t.minute && second == t.second){
        return true;
    } else {
        return false;
    }
}

auto s24569::Time::operator!= (Time const& t) const -> bool
{
    if (hour != t.hour && minute != t.minute && second != t.second){
        return true;
    } else {
        return false;
    }
}

// seconds to midnight- functions
auto s24569::Time::count_seconds() const -> uint64_t
{
    return second + minute * 60 + hour * 3600;
}

auto s24569::Time::count_minutes() const -> uint64_t
{
    return minute + hour * 60;
}

auto s24569::Time::time_to_midnight() const -> Time
{
    auto current = s24569::Time{hour,minute,second};
    auto result = s24569::Time{23,59,59};
    result = result - current;
    result.next_second();
    return result;
}


//main
auto main() -> int
{
    auto time = s24569::Time{23, 59, 59};
    std::cout << "to_string()\n" << time.to_string() << "\n";

    time = s24569::Time{23,59,59};
    std::cout << "next_hour()\n" << time.to_string() << " -> ";
    time.next_hour();
    std::cout << time.to_string() << "\n";

    time = s24569::Time{23,59,59};
    std::cout << "next_minute()\n" << time.to_string() << " -> ";
    time.next_minute();
    std::cout << time.to_string() << "\n";

    time = s24569::Time{23,59,59};
    std::cout << "next_second()\n" << time.to_string() << " -> ";
    time.next_second();
    std::cout << time.to_string() << "\n";

// time of day
    time = s24569::Time{23,59,59};
    std::cout << "to_sring(time_of_day())\n" << time.to_string() << " -> "
              << time.to_string(time.time_of_day()) << "\n";

// arithmetic
    time = s24569::Time{20,10,30};
    auto time2 = s24569::Time{4,36,23};
    auto time3 = time + time2;

    std::cout << "operator+\n"
              << time.to_string() << " + " << time2.to_string()
              << " = " << time3.to_string() << "\n";

    time3 = time - time2;
    std::cout << "operator-\n"
              << time.to_string() << " - " << time2.to_string()
              << " = " << time3.to_string() << "\n";

    time = s24569::Time{20,10,30};
    time2 = s24569::Time{4,36,23};
    std::cout << "operator<\n"
              << time.to_string() << " < " << time2.to_string() << " -> ";
    if (time < time2){
        std::cout << "TRUE\n";
    } else {
        std::cout << "FASLE\n";
    }

    std::cout << "operator>\n"
              << time.to_string() << " > " << time2.to_string() << " -> ";
    if (time > time2){
        std::cout << "TRUE\n";
    } else {
        std::cout << "FALSE\n";
    }

    std::cout << "operator==\n"
              << time.to_string() << " == " << time2.to_string() << " -> ";
    if (time == time2){
        std::cout << "TRUE\n";
    } else {
        std::cout << "FALSE\n";
    }

    std::cout << "operator!=\n"
              << time.to_string() << " != " << time2.to_string() << " -> ";
    if (time > time2){
        std::cout << "TRUE\n";
    } else {
        std::cout << "FALSE\n";
    }

// seconds to midnight
    time = s24569::Time{14,30,30};
    std::cout << "count_seconds()\n"
              << time.to_string() << " -> "
              << time.count_seconds() << "\n";

    std::cout << "count_minutes()\n"
              << time.to_string() << " -> "
              << time.count_minutes() << "\n";

    std::cout << "time_to_midnight()\n"
              << time.to_string() << " -> ";
    auto to_midnight =  time.time_to_midnight();
    std::cout << to_midnight.to_string() << "\n";

    return 0;
}
