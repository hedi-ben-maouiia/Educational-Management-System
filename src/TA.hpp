#ifndef TA_H_
#define TA_H_
#include "persons.hpp"


class teacher_ass : public person{
    public:
        teacher_ass();
        std::string to_string();
        int show_ta_menu();
    private:

};



#endif // TA_H_

