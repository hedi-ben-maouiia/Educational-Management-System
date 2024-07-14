#ifndef COURSES_H_
#define COURSES_H_
#include <iostream>
#include <vector>

class  courses
{
    public:
        std::string to_string();


    private:
        std::size_t code;
        std::string name;
        std::string author;
        std::vector<std::size_t> registred_students_ids;


};


#endif // COURSES_H_

