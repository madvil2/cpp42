#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    int currentSize;
    int oldestIndex;

    std::string truncateString(const std::string &str) const;
    void displayContactRow(int index) const;
    bool isValidIndex(const std::string &input) const;

public:
    PhoneBook();
    
    void addContact(const Contact &contact);
    void searchContacts() const;
    int getCurrentSize() const;
};

#endif 