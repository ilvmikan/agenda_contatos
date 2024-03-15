#include "agenda.h"
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

#ifdef _WIN32
#include <cstdlib>
#define CLEAR_SCREEN "cls"
#else
#include <unistd.h>
#define CLEAR_SCREEN "clear"
#endif

std::vector<Contact> contacts;

void clear_screen()
{
    std::system(CLEAR_SCREEN);
}

void add_ctt()
{
    Contact newContact;

    clear_screen();
    std::cout << "ADD CONTACT" << std::endl;

    std::cout << "Name: ";
    std::getline(std::cin, newContact.name);

    while (true)
    {
        std::cout << "Alias: ";
        std::getline(std::cin, newContact.alias);

        if (newContact.alias.empty())
        {
            std::cout << "Alias cannot be empty" << std::endl;
            continue;
        }

        break;
    }

    std::cout << "Phone number: ";
    std::getline(std::cin, newContact.phoneNumber);

    std::cout << "Email: ";
    std::getline(std::cin, newContact.email);

    contacts.push_back(newContact);
}

void rm_ctt()
{
    clear_screen();
    std::string entry;
    std::vector<Contact> newCttVector;


    std::cout << "REMOVE CONTACT" << std::endl;

    do
    {
        std::cout << "Contact ALIAS to remove\n";
        std::cout << "Do not remember? Type 1\n";
        std::cout << "Quit? Type 0\n\n>> ";
        std::getline(std::cin, entry);

        if (entry == "1")
        {
            show_all();
            clear_screen();
        }
        else if (entry == "0")
        {
            return;
        }

    } while (entry == "1");

    clear_screen();

    for (const auto &contact : contacts)
    {
        if (contact.alias != entry)
        {
            newCttVector.push_back(contact);
        }
    }

    contacts = newCttVector;
}

void edit_ctt()
{
    clear_screen();
    std::string entry;
    std::vector<Contact> newCttVector;

    do
    {
        std::cout << "Contact name or alias to edit\n";
        std::cout << "Do not remember? Type 1\n";
        std::cout << "Quit? Type 0\n\n>> ";
        std::getline(std::cin, entry);

        if (entry == "1")
        {
            show_all();
            clear_screen();
        }
        else if (entry == "0")
        {
            return;
        }

    } while (entry == "1");

    clear_screen();

    for (auto &contact : contacts)
    {
        if (contact.alias == entry || contact.name == entry)
        {
            int opt = 0;

            std::cout << "What you want to edit?\n"
                      << "[1] name: " << contact.name << "\n"
                      << "[2] alias: " << contact.alias << "\n"
                      << "[3] phone number: " << contact.phoneNumber << "\n"
                      << "[4] email: " << contact.email << "\n"
                      << ">> ";

            std::cin >> opt;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (opt)
            {
            case 1:
            {
                std::string newName;
                std::cout << "New name: ";
                std::getline(std::cin, newName);
                contact.name = newName;
                break;
            }
            case 2:
            {
                std::string newAlias;
                std::cout << "New alias: ";
                std::getline(std::cin, newAlias);
                contact.alias = newAlias;
                break;
            }
            case 3:
            {
                std::string newPhoneNumber;
                std::cout << "New phone number: ";
                std::getline(std::cin, newPhoneNumber);
                contact.phoneNumber = newPhoneNumber;
                break;
            }
            case 4:
            {
                std::string newEmail;
                std::cout << "New email: ";
                std::getline(std::cin, newEmail);
                contact.email = newEmail;
                break;
            }
            default:
                std::cout << "Invalid option" << std::endl;
                break;
            }
        }
    }
}

void show_all()
{
    clear_screen();
    int i = 0;

    std::cout << "ALL CONTACTS > NAME  |  ALIAS\n";

    for (const Contact &contact : contacts)
    {
        i++;
        std::cout << i << ": "
                  << contact.name
                  << "  |  "
                  << contact.alias
                  << std::endl;
    }

    std::cout << "press enter...";
    std::cin.get();
}

void search()
{
    clear_screen();

    std::cout << "SEARCH" << std::endl;
    std::string entry;

    do
    {
        std::cout << "Contact name or alias to search\n";
        std::cout << "Do not remember? Type 1\n";
        std::cout << "Quit? Type 0\n\n>> ";
        std::getline(std::cin, entry);

        if (entry == "1")
        {
            show_all();
            clear_screen();
        }
        else if (entry == "0")
        {
            return;
        }

    } while (entry == "1");

    std::string lowerEntry = entry;
    std::transform(lowerEntry.begin(), lowerEntry.end(), lowerEntry.begin(), ::tolower);

    bool found = false;

    for (const Contact &contact : contacts)
    {
        std::string lowerName = contact.name;
        std::string lowerAlias = contact.alias;
        std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
        std::transform(lowerAlias.begin(), lowerAlias.end(), lowerAlias.begin(), ::tolower);

        if (lowerName == lowerEntry || lowerAlias == lowerEntry)
        {
            clear_screen();
            std::cout << "Name: " << contact.name << std::endl;
            std::cout << "Alias: " << contact.alias << std::endl;
            std::cout << "Phone number: " << contact.phoneNumber << std::endl;
            std::cout << "Email: " << contact.email << std::endl
                      << std::endl;
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "No contact found" << std::endl;
    }

    std::cout << "press enter...";
    std::cin.get();
}