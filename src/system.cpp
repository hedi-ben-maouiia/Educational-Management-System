#include "system.hpp"
#include "helper.hpp"
#include "persons.hpp"
#include <sstream>
#include <string>
#include <utility>

void system::run_system()
{
    while(true){
        system sys;
        doctor dc;
        student st;
        teacher_ass ta;
        courses cr;
        std::vector<doctor*> doc_db;
        std::vector<student*> std_db;
        std::vector<teacher_ass*> ta_db;
        std::map<std::string,std::pair<std::string,attribute>> users;

        load_data_base(users,doc_db,std_db,ta_db);

        attribute att  = access_system(sys,dc,st,ta,cr,users);
        int choice = 0;

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

attribute system::access_system(sys &sys,doctor &doc,student &st,teacher_ass &ta,courses &courses,std::map<std::string,std::pair<std::string,attribute>>&users)
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
            {
                int log = sys.login(users);
                if(log == -1)
                    access_system(sys,doc,st,ta,courses,users);
                else
                    cur_user_attribute = (attribute)log;
                break;
            }
        case 2:
            {
                int sign = sys.sign_up(users);
                if(sign == 4)
                    access_system(sys,doc,st,ta,courses,users);
                else
                    cur_user_attribute = (attribute)sign ;
                break;
            }
        case 3:
            std::exit(0);
    }
    return cur_user_attribute;
}

int system::login(std::map<std::string,std::pair<std::string,attribute>>&users)
{
    std::string user_name,password;
    std::getline(std::cin,user_name);
    input("Enter users name: ",user_name);
    input("Enter password: ",password);
    if(users.count(user_name)){
        if(users[user_name].first.compare(password) == 0)
            return (int)users[user_name].second;
    }
    std::cout << "Wrong user name or password ! please try again...\n";
    return -1;
}

int system::sign_up(std::map<std::string,std::pair<std::string,attribute>> &users)
{
    std::string full_name,user_name,password,pass_confirmation,email;
    std::vector<std::string> menu_content;
    menu_content.push_back("Sign-Up as a doctot?");
    menu_content.push_back("Sign-Up as a student?");
    menu_content.push_back("Sign-Up as a teacher assistent?");
    menu_content.push_back("Cancel.");

    int att = show_menu(menu_content);

    if(att == 4)
        return att;

    std::getline(std::cin,user_name);
    check_user(users,user_name,"Enter user name: ","This user name is already taken. Try another one.\n",user_name_exist);
    input("Enter Full Name: ",full_name);
    check_email(email,"Enter Email: ","Pleas enter a valid email \"exampale@gmail.com\"\n",check_email_failed);

    while(true){
        input("Enter password: ",password);
        input("Conferm password: ",pass_confirmation);
        if(password.compare(pass_confirmation) != 0)
            std::cout << "Your password are not identical! try again\n";
        else
            break;
    }

    std::ostringstream oss;
    std::vector<std::string> lines;
    oss << user_name << "," << password << "," << att;
    lines.push_back(oss.str());
    save_data("databases/users.txt",lines,true); // save the new users to the databases
    users[user_name] =  std::make_pair(password,(attribute) att); // add the new users to the map of all the users in the system
    return att;
}

void system::load_data_base(std::map<std::string,std::pair<std::string,attribute>>&users,std::vector<doctor*> &doctors_db,std::vector<student*> &students_db,std::vector<teacher_ass*> &ta_db)
{
    // Load users to map from user_name --> <password , attribute>
    std::vector<std::string> user_data(0);
    user_data = fetch_data("databases/users.txt",user_data);
    for(auto &str : user_data){
        std::vector<std::string> line;
        split_string(str,line,',');
        users[line[0]] = std::make_pair(line[1],(attribute)to_int(line[2]));
    }
}
