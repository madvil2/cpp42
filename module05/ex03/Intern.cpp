#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>


Intern::Intern() {
}


Intern::Intern(const Intern& other) {
    (void)other; 
}


Intern& Intern::operator=(const Intern& other) {
    (void)other; 
    return *this;
}


Intern::~Intern() {
}


typedef AForm* (*FormCreator)(const std::string&);


static AForm* createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    
    struct FormType {
        std::string name;
        FormCreator creator;
    };

    const FormType formTypes[] = {
        {"shrubbery creation", createShrubberyForm},
        {"robotomy request", createRobotomyForm},
        {"presidential pardon", createPresidentialForm}
    };

    const int numFormTypes = sizeof(formTypes) / sizeof(FormType);

    
    for (int i = 0; i < numFormTypes; ++i) {
        if (formName == formTypes[i].name) {
            AForm* form = formTypes[i].creator(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }

    
    std::cerr << "Intern cannot create form: " << formName << " (form not found)" << std::endl;
    throw FormNotFoundException();
}


const char* Intern::FormNotFoundException::what() const throw() {
    return "Form type not found!";
}
