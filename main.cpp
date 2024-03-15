#include <iostream>
#include "agenda.h"
#include <limits>
#include <cstdlib>

void add_ctt();
void rm_ctt();
void edit_ctt();
void show_all();
void clear_screen();
void search();

int main()
{
    int entry;

    do
    {
        clear_screen();
        std::cout << " >>>>>> contact book <<<<<<" << std::endl;
        std::cout << "1. add contact" << std::endl;
        std::cout << "2. rm contact" << std::endl;
        std::cout << "3. edit contact" << std::endl;
        std::cout << "4. show all contacts" << std::endl;
        std::cout << "5. search" << std::endl;
        std::cout << "0. exit" << std::endl;
        std::cout << ">> ";
        std::cin >> entry;

        if (std::cin.fail())
        {
            std::cerr << "err: invalid entry" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        switch (entry)
        {
        case 0:
            std::cout << "goodbye." << std::endl;
            break;
        case 1:
            add_ctt();
            break;
        case 2:
            rm_ctt();
            break;
        case 3:
            edit_ctt();
            break;
        case 4:
            show_all();
            break;
        case 5:
            search();
            break;
        default:
            std::cout << "invalid entry" << std::endl;
            break;
        }

    } while (entry != 0);

    return 0;
}
