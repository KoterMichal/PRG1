#include <iostream>
#include <string>
#include <list>
#include "Student2.h"

std::list<Student> list_of_Student;

auto display() -> void
{
    system("clear");
    std::cout << "The contents of the list:\n";

    for(std::list<Student>::iterator i=list_of_Student.begin(); i!= list_of_Student.end(); ++i)
    {
        auto someone = *i;
        std::cout << someone.to_string() << "\n";
    }
    std::cout << "\n";
}

auto push_back() -> void
{
    std::string firstname;
    std::string lastname;
    std::string indexbook;
    std::string s_term;
    std::string s_grade;
    unsigned short i_term;
    float f_grade;

    std::cout << "Enter information:\n"
         << "Firstname: ";
    std::getline(std::cin, firstname);
    std::cout << "Lastname: ";
    std::getline(std::cin, lastname);
    std::cout << "Indexbook: ";
    std::getline(std::cin, indexbook);
    std::cout << "Term: ";
    std::getline(std::cin, s_term);
    i_term = std::stoi(s_term);
    std::cout << "Average grade: ";
    std::getline(std::cin, s_grade);
    f_grade = std::stof(s_grade);

    auto someone = Student{firstname, lastname, indexbook, i_term, f_grade};
    list_of_Student.push_back(someone);

    system("clear");
    std::cout << someone.to_string() << " has been added from the list\n\n";
}

auto remove() -> void
{
    std::string indexbook;

    std::cout << "Enter the index book of Student to be deleted: ";
    std::getline(std::cin, indexbook);
    auto to_remove = Student{indexbook};

    list_of_Student.remove(to_remove);

    system("clear");
    std::cout << "Student with index book: " << indexbook << " has been reomved from the list\n\n";
}

auto exit() -> void
{
    std::cout << "End of program\n\n";
}

auto main() -> int{
    system("clear");
    std::string s_choice;
    int i_choice;
    do{
        std::cout << "MENU\n"
                  << "--------------------------\n"
                  << "1. Add new Student\n"
                  << "2. Show list\n"
                  << "3. Remove Student from list\n"
                  << "4. Exit\n"
                  << "--------------------------\n"
                  << "Choise number: ";
        std::getline(std::cin,s_choice);
        i_choice = std::stoi(s_choice);
        std::cout << "\n";

        switch(i_choice) {
            case 1: push_back(); break;
            case 2: display(); break;
            case 3: remove(); break;
            case 4: exit(); break;
            default:
                std::cout << "WRONG NUMBER!\n";
                break;
        }
    }while(i_choice != 4);

    return 0;
}
