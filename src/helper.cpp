#include "helper.hpp"
#include "persons.hpp"
#include "system.hpp"
#include <error.h>
#include <fstream>
#include <ios>
#include <sstream>
#include <stdexcept>
#include <string>
#include <stack>

bool user_name_exist(std::string user_name,std::map<std::string,std::pair<std::string,attribute>> &users)
{
    if(users.count(user_name))
        return false;
    return true;
}
bool is_alpha(const char c)
{
    return ( 'A' <= c && c <= 'z');
}

bool check_email_failed(std::string email)
{
    int len = email.length();
    if(!is_alpha(email[0]))
        return false;
    int alt,dot;
    alt = dot = -1;
    for(int i{0}; i < len;++i){
        if(email[i] == '@')
            alt = i;
        if(email[i] == '.')
            dot = i;
    }
    if(alt == -1 || dot == -1)
        return false;
    if(alt > dot)
        return false;
    return !(dot >= ( len - 1) );
}
void check_user(std::map<std::string,std::pair<std::string,attribute>>&users,std::string &buffer,const std::string input_msg,const std::string err_msg,bool (*func)(std::string str,std::map<std::string,std::pair<std::string,attribute>>&users))
{
    while(true){
        input(input_msg,buffer);
        if(!func(buffer,users))
            std::cout << err_msg;
        else
            break;
    }

}
void check_email(std::string &buffer,const std::string input_msg,const std::string err_msg,bool (*func)(std::string str))
{
    while(true){
        input(input_msg,buffer);
        if(!func(buffer))
            std::cout << err_msg;
        else
            break;
    }
}
void input(const std::string msg,std::string &buffer)
{
    std::cout << msg;
    std::getline(std::cin,buffer);
    buffer[buffer.size()] = '\0';
}

std::vector<std::string> fetch_data(const std::string file_path,std::vector<std::string> &data_fetched)
{
    std::ifstream data_base;
    data_base.open(file_path);
    if(data_base.fail()){
        throw std::invalid_argument("Cannot open file for reading\n");
    }
    std::string line;
    while(std::getline(data_base,line)){
        data_fetched.push_back(line);
    }
    data_base.close();

    return data_fetched;
}

void save_data(const std::string file_path, std::vector<std::string> &data_to_store, bool append = true)
{

    if(data_to_store.size() == 0){
        throw std::invalid_argument("data_to_store is EMPTY!\n");
    }

    std::ios_base::openmode mode = std::ios::app;
    if(!append){
        mode = std::ios::trunc;
    }
    std::ofstream data_base;
    data_base.open(file_path,mode);
    if(data_base.fail()){
        throw std::invalid_argument("Cannot open file for write\n");
    }

    for(std::string str : data_to_store){
        data_base << str << "\n";
    }

    data_base.close();
}
std::vector<std::string> split_string(std::string to_splite ,std::vector<std::string> &splited_string,const char delim = ',')
{
    std::string token;
    std::stringstream ss(to_splite);
    while(getline(ss,token,delim)){
        splited_string.push_back(token);
    }
    return splited_string;
}
int to_int(std::string str)
{
    int number;
    std::stringstream ss(str);
    ss >> number;
    return number;
}
std::string to_str(int number)
{
    std::stack<char> st;
    std::string str;
    while(number){
        int dig = number % 10;
        st.push(dig + '0');
        number /= 10;
    }
    while(!st.empty())
        str.push_back(st.top()), st.pop();
    return str;
}
int read_choice(int size)
{
    int choice = 0;
    std::cout << "Enter a choice between 1 - " << size << ": ";
    std::string inp;
    std::cin >> inp;
    choice = to_int(inp);
    return choice;
}
int show_menu(std::vector<std::string> menu_content)
{
    int size = menu_content.size();
    int choice=0;
    std::cout << " Menu:\n";
    for(int i{0}; i < size; ++i)
        std::cout << "\t" << i+1 << " - " << menu_content[i] << ".\n";
    choice = read_choice(size);
    while(!(1 <= choice && choice <= size)){
        std::cout << "Pleas enter a valid number!\n";
        choice = read_choice(size);
    }
    return choice;
}
