#pragma once

#include <iostream>
#include <vector>
#include <map>

enum attribute{
    DOC = 1,
    STD = 2,
    TA = 3,
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

