#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "TA.hpp"
#include "students.hpp"
#include "doctors.hpp"
#include "persons.hpp"

class system {
    public:
        void load_data_base(std::vector<doctor*> *doctors_db,std::vector<student*> *students_db,std::vector<teacher_ass*> *ta_db);
        void update_data_base();
        void run_system();
        attribute access_system();
        attribute login();
        attribute sign_up();
        void logout();

    private:
        std::vector<doctor*> doctors_database;

};


#endif // SYSTEM_H_
