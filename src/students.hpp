#ifndef STUDENT_H_
#define STUDENT_H_
#include "types.hpp"
#include "courses.hpp"
#include "helper.hpp"
#include <vector>

class STUDENT {
    public:
        std::size_t id;
        std::string user_name;
        std::string full_name;
        std::string email;
        std::string password;
        ATTRIBUTE   att;
        std::vector<COURSES*> registred_courses;

    STUDENT() : id(0) , att(STD) {}
    STUDENT(std::string student_info);
    std::string to_string();

};



#endif // STUDENT_H_


