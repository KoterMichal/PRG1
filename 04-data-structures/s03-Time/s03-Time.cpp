#include <iostream>
#include "../include/s24569/Time.h"

// time- functions
auto s03::Time::to_string() const -> std::string
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

auto s03::Time::next_hour() -> void
{
    hour++;
    if (hour > 23){
        hour -= 24;
    }
}

auto s03::Time::next_minute() -> void
{
    minute++;
    if (minute > 59){
        minute -= 60;
        next_hour();
    }
}

auto s03::Time::next_second() -> void
{
    second++;
    if (second > 59){
        second -= 60;
        next_minute();
    }
}

// time of day- functions

auto s03::Time::time_of_day() const -> Time_of_day
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

auto s03::Time::to_string(Time_of_day time_of_day) -> std::string
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

auto s03::Time::operator+ (Time const& t) const -> Time
{
    s03::Time result(hour, minute, second);
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

auto s03::Time::operator- (Time const& t) const -> Time
{
    s03::Time result(hour, minute, second);
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

auto s03::Time::operator< (Time const& t) const -> bool
{
    s03::Time a(hour, minute, second);
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

auto s03::Time::operator> (Time const& t) const -> bool
{
    s03::Time a(hour, minute, second);
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

auto s03::Time::operator== (Time const& t) const -> bool
{
    s03::Time a(hour, minute, second);
    if (hour == t.hour && minute == t.minute && second == t.second){
        return true;
    } else {
        return false;
    }
}

auto s03::Time::operator!= (Time const& t) const -> bool
{
    s03::Time a(hour, minute, second);
    if (hour != t.hour && minute != t.minute && second != t.second){
        return true;
    } else {
        return false;
    }
}


auto main() -> int
{
    auto time = s03::Time{23, 59, 59};
    std::cout << "to_string()\n" << time.to_string() << "\n";

    time = s03::Time{23,59,59};
    std::cout << "next_hour()\n" << time.to_string() << "\n";
    time.next_hour();
    std::cout << time.to_string() << "\n";
    time.next_second();

    time = s03::Time{23,59,59};
    std::cout << "next_minute()\n" << time.to_string() << "\n";
    time.next_minute();
    std::cout << time.to_string() << "\n";

    time = s03::Time{23,59,59};
    std::cout << "next_second()\n" << time.to_string() << "\n";
    time.next_second();
    std::cout << time.to_string() << "\n";

// time of day
    time = s03::Time{23,59,59};
    std::cout << "to_sring(time_of_day())\n" << time.to_string() << "\n"
              << time.to_string(time.time_of_day()) << "\n";

// arithmetic
    time = s03::Time{20,10,30};
    auto time2 = s03::Time{4,36,23};
    auto time3 = time + time2;

    std::cout << "operator+\n"
              << time.to_string() << " + " << time2.to_string()
              << " = " << time3.to_string() << "\n";

    time3 = time - time2;
    std::cout << "operator-\n"
              << time.to_string() << " - " << time2.to_string()
              << " = " << time3.to_string() << "\n";

    time = s03::Time{20,10,30};
    time2 = s03::Time{4,36,23};
    std::cout << "operator<\n"
              << time.to_string() << " < " << time2.to_string() << "\n";
    if (time < time2){
        std::cout << "TRUE\n";
    } else {
        std::cout << "FASLE\n";
    }

    std::cout << "operator>\n"
              << time.to_string() << " > " << time2.to_string() << "\n";
    if (time > time2){
        std::cout << "TRUE\n";
    } else {
        std::cout << "FALSE\n";
    }

    std::cout << "operator==\n"
              << time.to_string() << " == " << time2.to_string() << "\n";
    if (time == time2){
        std::cout << "TRUE\n";
    } else {
        std::cout << "FALSE\n";
    }

    std::cout << "operator!=\n"
              << time.to_string() << " != " << time2.to_string() << "\n";
    if (time > time2){
        std::cout << "TRUE\n";
    } else {
        std::cout << "FALSE\n";
    }




    return 0;
}
