#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : currentSize(0), oldestIndex(0) {}

std::string PhoneBook::truncateString(const std::string &str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::addContact(const Contact &contact) {
    contacts[oldestIndex] = contact;
    if (currentSize < MAX_CONTACTS)
        currentSize++;
    oldestIndex = (oldestIndex + 1) % MAX_CONTACTS;
}

void PhoneBook::displayContactRow(int index) const {
    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << truncateString(contacts[index].getFirstName());
    std::cout << "|" << std::setw(10) << truncateString(contacts[index].getLastName());
    std::cout << "|" << std::setw(10) << truncateString(contacts[index].getNickname());
    std::cout << "|" << std::endl;
}

bool PhoneBook::isValidIndex(const std::string &input) const {
    if (input.empty() || input.length() > 1)
        return false;
    if (!isdigit(input[0]))
        return false;
    int index = input[0] - '0';
    return index >= 0 && index < currentSize;
}

void PhoneBook::searchContacts() const {
    if (currentSize == 0) {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    
    for (int i = 0; i < currentSize; i++)
        displayContactRow(i);
    
    std::cout << "|-------------------------------------------|" << std::endl;

    std::string input;
    std::cout << "Enter index to display contact details: ";
    std::getline(std::cin, input);

    if (!isValidIndex(input)) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    int index = input[0] - '0';
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

int PhoneBook::getCurrentSize() const {
    return currentSize;
} 