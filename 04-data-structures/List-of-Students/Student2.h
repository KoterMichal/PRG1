#ifndef Student2_h
#define Student2_h
#include <sstream>
#include <string>

struct Student{
    std::string const firstname;
    std::string lastname;
    std::string const index_book;
    unsigned short term;
    float average_grade;

    Student() = default;
    Student(std::string const ib)
        : index_book{ib}
    {}
    Student(std::string const firstn, std::string lastn, std::string const ib, unsigned short t, float ag)
        : firstname{firstn}
        , lastname{lastn}
        , index_book{ib}
        , term{t}
        , average_grade{ag}
    {}

    auto to_string() const -> std::string
    {
        auto out = std::ostringstream{};
        out << firstname << " " << lastname << " (" << index_book << "), term: " << term << " average grade: " << average_grade;
        return out.str();
    }

    auto operator== (Student const& stu) const -> bool
    {
        if (index_book == stu.index_book){
            return true;
        } else {
            return false;
        }
    }

    auto operator!= (Student const& stu) const -> bool
    {
        if (index_book != stu.index_book){
            return true;
        } else {
            return false;
        }
    }
};

#endif
