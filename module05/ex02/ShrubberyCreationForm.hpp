#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
public:
    // Orthodox Canonical Form
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    // Execute function
    virtual void execute(Bureaucrat const & executor) const;

    // Exception class
    class FileOpenException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif // SHRUBBERYCREATIONFORM_HPP
