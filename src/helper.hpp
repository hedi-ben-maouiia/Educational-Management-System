#ifndef HELPER_H_
#define HELPER_H_
#include <iostream>
#include <vector>


std::vector<std::string> fetch_data(const std::string file_path,std::vector<std::string> &data_fetched);
void                     save_data(const std::string file_path,std::vector<std::string> &data, bool append);
int                      to_int(const std::string str);
int                      read_choice(int size);
std::vector<std::string> split_string(std::string to_splite ,std::vector<std::string> &splited_string,const char delim);
int                      show_menu(std::vector<std::string> menu_content);

#endif // HELPER_H_


