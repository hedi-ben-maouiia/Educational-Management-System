#ifndef DOCTOR_H_
#define DOCTOR_H_
#include <iostream>
#include "types.h"
#include "courses.h"

class DOCTOR { 
    public:
        std::size_t id;
        std::string user_name;
        std::string full_name;
        std::string email;
        std::string password;  
        ATTRIBUTE   att;
        std::vector<COURSES*> courses_count;

        std::string to_string(); // from doctor to string to save it in database as one string          
};


#endif // DOCTOR_H_
