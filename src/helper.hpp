#ifndef HELPER_H_
#define HELPER_H_
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <vector>
#include <utility>
#include "persons.hpp"

std::vector<std::string> fetch_data(const std::string file_path,std::vector<std::string> &data_fetched);
void                     save_data(const std::string file_path,std::vector<std::string> &data, bool append);
int                      to_int(const std::string str);
std::string              to_str(int number);
int                      read_choice(int size);
std::vector<std::string> split_string(std::string to_splite ,std::vector<std::string> &splited_string,const char delim);
int                      show_menu(std::vector<std::string> menu_content);
void                     input(const std::string msg,std::string &buffer);
void                     check_user(std::map<std::string,std::pair<std::string,attribute>>&users,std::string &buffer,const std::string input_msg,const std::string err_msg,bool (*func)(std::string str,std::map<std::string,std::pair<std::string,attribute>>&users));
void                     check_email(std::string &buffer,const std::string input_msg,const std::string err_msg,bool (*func)(std::string str));
bool                     user_name_exist(std::string user_name,std::map<std::string,std::pair<std::string,attribute>> &users);
bool                     check_email_failed(std::string email);
bool                     is_alpha(const char c);
#endif // HELPER_H_


