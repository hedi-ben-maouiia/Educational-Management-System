#include "helper.hpp"
#include <error.h>
#include <fstream>
#include <ios>
#include <sstream>
#include <stdexcept>
#include <string>

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

