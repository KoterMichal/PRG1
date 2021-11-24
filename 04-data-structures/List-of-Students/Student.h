#ifndef Student_h
#define Student_h
#include <iostream>
#include <sstream>
#include <string>

namespace Student {

struct Student{
    std::string const firstname;
    std::string forname;
    std::string const index_book;
    unsigned short term;
    float average_grade;

    Student() = default;
    Student(std::string const, std::string, std::string const, unsigned short, float);

    auto to_string() const -> std::string;
};

}
#endif
