#ifndef COURSES_H_
#define COURSES_H_
#include <iostream>
#include <vector>

class  COURSES
{
    public:
        std::size_t code;
        std::string name;
        std::string author;
        std::vector<std::size_t> registred_students_ids;


        std::string to_string();
};


#endif // COURSES_H_

