#include <iostream>
#include "Time.h"


auto main() -> int
{
// time
    auto time = Time{23, 59, 59};
    std::cout << "to_string()\n" << time.to_string() << "\n";

    time = Time{23,59,59};
    std::cout << "next_hour()\n" << time.to_string() << " -> ";
    time.next_hour();
    std::cout << time.to_string() << "\n";

    time = Time{23,59,59};
    std::cout << "next_minute()\n" << time.to_string() << " -> ";
    time.next_minute();
    std::cout << time.to_string() << "\n";

    time = Time{23,59,59};
    std::cout << "next_second()\n" << time.to_string() << " -> ";
    time.next_second();
    std::cout << time.to_string() << "\n";

// time of day
    time = Time{23,59,59};
    std::cout << "to_sring(time_of_day())\n" << time.to_string() << " -> "
              << time.to_string(time.time_of_day()) << "\n";

// arithmetic
    time = Time{20,10,30};
    auto time2 = Time{4,36,23};
    auto time3 = time + time2;

    std::cout << "operator+\n"
              << time.to_string() << " + " << time2.to_string()
              << " = " << time3.to_string() << "\n";

    time3 = time - time2;
    std::cout << "operator-\n"
              << time.to_string() << " - " << time2.to_string()
              << " = " << time3.to_string() << "\n";

    time = Time{20,10,30};
    time2 = Time{4,36,23};
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
    time = Time{14,30,30};
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
