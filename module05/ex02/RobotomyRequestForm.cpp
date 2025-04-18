#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45, "default") {
}


RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45, target) {
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other) {
}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}


RobotomyRequestForm::~RobotomyRequestForm() {
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    
    checkExecuteRequirements(executor);
    
    
    std::cout << "* DRILLING NOISES * Bzzzzz... Whirrrrr... Clank! Clank!" << std::endl;
    
    
    std::srand(std::time(0));
    
    
    if (std::rand() % 2) {
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy of " << getTarget() << " has failed!" << std::endl;
    }
}
