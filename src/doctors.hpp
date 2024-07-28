#ifndef DOCTOR_H_
#define DOCTOR_H_

//#include "courses.hpp"
#include "courses.hpp"
#include "persons.hpp"
#include "helper.hpp"

class doctor : public person, private courses {
    private:
        std::vector<courses*> courses_list;
        unsigned int          courses_count;

    public:
        doctor();
        doctor(std::string str,courses *course);
        std::string to_string();
        int  show_doctor_menu();
};


#endif // DOCTOR_H_
