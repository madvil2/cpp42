#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>


PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5, "default") {
}


PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5, target) {
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other) {
}


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}


PresidentialPardonForm::~PresidentialPardonForm() {
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    
    checkExecuteRequirements(executor);
    
    
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
