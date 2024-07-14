#include "persons.hpp"

person::person(){}

person::person(std::string str)
{
    std::vector<std::string> sys;
    sys = split_string(str,sys,',');
    person::id         = to_int(sys[0]);
    person::user_name  = sys[1];
    person::full_name  = sys[2];
    person::email      = sys[3];
    person::password   = sys[4];
    person::att        = (attribute)to_int(sys[5]);
}

