#ifndef Student_h
#define Student_h
#include <iostream>
#include <sstream>
#include <string>

struct Student{
    std::string const firstname;
    std::string forname;
    std::string const index_book;
    unsigned short term;
    float average_grade;

    Student() = default;
    Student(std::string const firstn, std::string forn, std::string const ib, unsigned short t, float ag)
        : firstname{std::move(firstn)}
        , forname{std::move(forn)}
        , index_book{std::move(ib)}
        , term{t}
        , average_grade{ag}
    {}
    
    auto to_string() const -> std::string;
        auto out = std::ostringstream{};
        out << firstname << " " << forname << " (" << index_book << "), term: " << term << " avarage grade: " << average_grade;
        return out.str();
};

#endif
