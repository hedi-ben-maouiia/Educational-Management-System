#pragma once

#include <iostream>
#include <vector>
#include "helper.hpp"

enum attribute{
    DOC,
    STD,
    TA,
};

class person {

    public:
        person();
        person(std::string str);
        std::size_t id;
        std::string user_name;
        std::string full_name;
        std::string email;
        std::string password;
        attribute   att;

};

