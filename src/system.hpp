#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "TA.hpp"
#include "students.hpp"
#include "doctors.hpp"
#include "persons.hpp"
#include <utility>




class system {
    public:
        attribute                         access_system(system &sys,doctor &doc,student &st,teacher_ass &ta,courses &courses,std::map<std::string,std::pair<std::string,attribute>> &users);
        int                               login(std::map<std::string,std::pair<std::string,attribute>>&users);
        int                               sign_up(std::map<std::string,std::pair<std::string,attribute>> &users);
        void                              load_data_base(std::map<std::string,std::pair<std::string,attribute>>&users,std::vector<doctor*> &doctors_db,std::vector<student*> &students_db,std::vector<teacher_ass*> &ta_db);
        void                              update_data_base(std::map<std::string,std::string> &users);
        void                              run_system();
        std::map<std::string,std::string> get_users();
        std::vector<doctor*>              get_doctors();
        std::vector<student*>             get_students();
        std::vector<teacher_ass*>         get_teachers_ass();

        std::vector<doctor*>                doctors;
        std::vector<student*>               students;
        std::vector<teacher_ass*>           teachers_ass;
        std::map<std::string, std::string > users;
};

typedef class system sys;

#endif // SYSTEM_H_
