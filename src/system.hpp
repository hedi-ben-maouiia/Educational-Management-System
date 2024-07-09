#ifndef SYSTEM_H_
#define SYSTEM_H_
#include "doctors.h"
#include "TA.h"
#include "students.h"
#include "types.h"
#include <vector>

class SYSTEM { 
    public:
        std::vector<DOCTOR*> doctors_database;
    
        void loead_data_base(std::vector<DOCTOR*> *doctors_db,std::vector<STUDENT*> *students_db,std::vector<TEACHER_ASS*> *ta_db);
        void update_data_base();
        void login();
        void sign_up(); 
};


#endif // SYSTEM_H_
