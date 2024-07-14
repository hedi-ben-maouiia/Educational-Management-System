#ifndef DOCTOR_H_
#define DOCTOR_H_
#include "courses.hpp"
#include "persons.hpp"

class doctor : public person {
    private:
        std::vector<courses*> created_courses;
        std::size_t           courses_count;

    public:
        doctor();
        doctor(std::string str,courses *course);
        std::string to_string();
        int  show_doctor_menu();
};


#endif // DOCTOR_H_
