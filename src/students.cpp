#include "students.hpp"

student::student() : person::person()
{
}


int student::show_student_menu()
{
    std::vector<std::string> menu_content;
    menu_content.push_back("Register in Course");
    menu_content.push_back("List my Courses");
    menu_content.push_back("View Course");
    menu_content.push_back("Grade Report");
    menu_content.push_back("Logout");
    int choice = show_menu(menu_content);
    return choice;
}



