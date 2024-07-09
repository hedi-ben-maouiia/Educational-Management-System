#ifndef TA_H_
#define TA_H_

#include "types.hpp"


class TEACHER_ASS {

    public:
        std::size_t id;
        std::string user_name;
        std::string full_name;
        std::string email;
        std::string password;
        ATTRIBUTE   att;

        std::string to_string();
};



#endif // TA_H_

