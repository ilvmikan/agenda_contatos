#ifndef AGENDA_H
#define AGENDA_H

#include <string> 

struct Contact {
    std::string name;
    std::string alias;
    std::string phoneNumber;
    std::string email;
};

void clear_screen();

void add_ctt();
void rm_ctt();
void edit_ctt();
void show_all();
void search();

#endif 
