#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
public:
    // Orthodox Canonical Form
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    // Make form function
    AForm* makeForm(const std::string& formName, const std::string& target) const;

    // Exception class
    class FormNotFoundException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif // INTERN_HPP
