#include "PhoneBook.hpp"
#include <iostream>

static bool getContactInfo(Contact &contact) {
    std::string input;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, input);
    if (input.empty()) return false;
    contact.setFirstName(input);

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, input);
    if (input.empty()) return false;
    contact.setLastName(input);

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, input);
    if (input.empty()) return false;
    contact.setNickname(input);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, input);
    if (input.empty()) return false;
    contact.setPhoneNumber(input);

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, input);
    if (input.empty()) return false;
    contact.setDarkestSecret(input);

    return true;
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "EXIT")
            break;
        else if (command == "ADD") {
            Contact newContact;
            if (getContactInfo(newContact))
                phoneBook.addContact(newContact);
            else
                std::cout << "Contact not added: Empty fields are not allowed!" << std::endl;
        }
        else if (command == "SEARCH")
            phoneBook.searchContacts();
        else
            std::cout << "Invalid command!" << std::endl;
    }

    return 0;
} 