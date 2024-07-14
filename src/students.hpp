#ifndef STUDENT_H_
#define STUDENT_H_
#include "courses.hpp"
#include "persons.hpp"

class student : public person
{
    public:
        student();
        student(std::string str);
        std::string to_string();
        int show_student_menu();

    private:
        std::vector<courses*> registred_courses;
};



#endif // STUDENT_H_


