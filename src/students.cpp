#include "students.hpp"
#include "helper.hpp"
#include "types.hpp"
#include <sstream>

STUDENT::STUDENT(std::string str)
{
    std::vector<std::string> info;
    info = split_string(str,info,',');
    STUDENT::id         = to_int(info[0]);
    STUDENT::user_name  = info[1];
    STUDENT::full_name  = info[2];
    STUDENT::email      = info[3];
    STUDENT::password   = info[4];
    STUDENT::att        = (ATTRIBUTE)to_int(info[5]);
}

std::string STUDENT::to_string()
{
    std::ostringstream os;
    os << STUDENT::id <<","<< STUDENT::user_name <<","<< STUDENT::full_name <<","<< STUDENT::email << "," << STUDENT::password<<","<< STUDENT::att;
    return os.str();
}


