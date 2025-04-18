#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    std::cout << "===== Testing Concrete Forms =====" << std::endl;

    
    Bureaucrat lowGrade("Intern", 140);
    Bureaucrat midGrade("Manager", 40);
    Bureaucrat highGrade("CEO", 3);

    std::cout << lowGrade << std::endl;
    std::cout << midGrade << std::endl;
    std::cout << highGrade << std::endl;

    
    std::cout << "\n----- Test 1: ShrubberyCreationForm -----" << std::endl;
    try {
        ShrubberyCreationForm shrubForm("garden");
        std::cout << shrubForm << std::endl;

        
        lowGrade.signForm(shrubForm);

        
        std::cout << "Attempting to execute with low grade bureaucrat:" << std::endl;
        lowGrade.executeForm(shrubForm);

        std::cout << "Attempting to execute with mid grade bureaucrat:" << std::endl;
        midGrade.executeForm(shrubForm);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << "\n----- Test 2: RobotomyRequestForm -----" << std::endl;
    try {
        RobotomyRequestForm robotForm("Marvin");
        std::cout << robotForm << std::endl;

        
        lowGrade.signForm(robotForm);

        
        midGrade.signForm(robotForm);

        
        midGrade.executeForm(robotForm);

        
        highGrade.executeForm(robotForm);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << "\n----- Test 3: PresidentialPardonForm -----" << std::endl;
    try {
        PresidentialPardonForm pardonForm("Arthur Dent");
        std::cout << pardonForm << std::endl;

        
        midGrade.signForm(pardonForm);

        
        highGrade.signForm(pardonForm);

        
        midGrade.executeForm(pardonForm);

        
        highGrade.executeForm(pardonForm);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << "\n----- Test 4: Executing unsigned form -----" << std::endl;
    try {
        ShrubberyCreationForm unsignedForm("backyard");
        std::cout << unsignedForm << std::endl;

        
        highGrade.executeForm(unsignedForm);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << "\n----- Test 5: Intern creates forms -----" << std::endl;

    Intern someRandomIntern;
    Bureaucrat boss("Big Boss", 1);

    
    try {
        
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;

        
        boss.signForm(*rrf);
        boss.executeForm(*rrf);

        delete rrf; 

        
        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Zoidberg");
        std::cout << *ppf << std::endl;

        
        boss.signForm(*ppf);
        boss.executeForm(*ppf);

        delete ppf; 

        
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "office");
        std::cout << *scf << std::endl;

        
        boss.signForm(*scf);
        boss.executeForm(*scf);

        delete scf; 
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    try {
        AForm* invalidForm = someRandomIntern.makeForm("coffee request", "Fry");
        if (invalidForm) { 
            std::cout << *invalidForm << std::endl;
            delete invalidForm;
        }
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
