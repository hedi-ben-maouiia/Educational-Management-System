#include <iostream>
#include <vector>
#include "students.hpp"
#include "helper.hpp"

int main()
{
    std::vector<std::string> data;
    data = fetch_data("databases/students.txt",data);
    STUDENT students(data[0]);
    std::string str = students.to_string();
    std::vector<std::string> v;
    v.push_back(str);
    save_data("databases/students.txt",v,true);

    return 0;
}
