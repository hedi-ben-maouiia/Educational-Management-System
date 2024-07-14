#include "system.hpp"



void system::run_system()
{
    while(true){
        attribute att  = access_system();
        int choice = 0;
        class doctor dc;
        class student st;
        class teacher_ass ta;
        switch(att)
        {
            case attribute::DOC:
                {
                    choice = dc.show_doctor_menu();
                    bool log_out = false;
                    while(!log_out){
                        switch(choice){
                            case 1:
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                            case 4:
                                log_out = true;
                                break;
                        }
                    }
                    break;
                }
            case attribute::STD:
                {
                    choice = st.show_student_menu();
                    bool log_out = false;
                    while(!log_out){
                        switch(choice){
                            case 1:
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                            case 4:
                                break;
                            case 5:
                                log_out = true;
                                break;
                        }
                    }
                    break;
                }
            case attribute::TA:
                {
                    choice = ta.show_ta_menu();
                    bool log_out = false;
                    while(!log_out){
                        switch(choice){
                            case 1:
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                            case 4:
                                log_out = true;
                                break;
                        }
                    }
                    break;
                }

        }
    }
}

attribute system::access_system()
{
    std::cout << "\n============Welcom To Educational Management System=============\n\n";

    std::vector<std::string>  menu_content;
    menu_content.push_back("Login");
    menu_content.push_back("Sign-Up");
    menu_content.push_back("Shutdown System");
    int choice = show_menu(menu_content);
    attribute cur_user_attribute;

    switch(choice){
        case 1:
            cur_user_attribute = login();
            break;
        case 2:
            cur_user_attribute = sign_up();
            break;
        case 3:
            std::exit(0);
    }
    return cur_user_attribute;
}

attribute system::login()
{
    return attribute::STD;
}
attribute system::sign_up()
{
    return attribute::DOC;
}

