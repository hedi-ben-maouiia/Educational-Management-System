#include "doctors.hpp"

doctor::doctor() : person::person(){
}
doctor::doctor(std::string str, courses *course) : person::person(str){
    created_courses.push_back(course);
    courses_count = 0;
}

int doctor::show_doctor_menu()
{
    std::vector<std::string> menu_content;
    menu_content.push_back("Create a Course");
    menu_content.push_back("List Courses");
    menu_content.push_back("View Course");
    menu_content.push_back("Logout");
    int choice = show_menu(menu_content);
    return choice;
}



