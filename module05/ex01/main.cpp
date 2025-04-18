#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "===== Testing Form Class =====" << std::endl;

    
    std::cout << "\n----- Test 1: Valid form creation -----" << std::endl;
    try {
        Form f1("Tax Form", 50, 25);
        std::cout << f1 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << "\n----- Test 2: Form with grade too high -----" << std::endl;
    try {
        Form f2("Invalid Form", 0, 25);
        std::cout << f2 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << "\n----- Test 3: Form with grade too low -----" << std::endl;
    try {
        Form f3("Invalid Form", 50, 151);
        std::cout << f3 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << "\n----- Test 4: Bureaucrat signs form successfully -----" << std::endl;
    try {
        Bureaucrat b1("John", 40);
        Form f4("Application Form", 50, 25);
        
        std::cout << "Before signing: " << f4 << std::endl;
        b1.signForm(f4);
        std::cout << "After signing: " << f4 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << "\n----- Test 5: Bureaucrat fails to sign form (grade too low) -----" << std::endl;
    try {
        Bureaucrat b2("Bob", 60);
        Form f5("Classified Form", 50, 25);
        
        std::cout << "Before signing attempt: " << f5 << std::endl;
        b2.signForm(f5);
        std::cout << "After signing attempt: " << f5 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << "\n----- Test 6: Form copy constructor and assignment operator -----" << std::endl;
    try {
        Form f6("Original Form", 50, 25);
        Bureaucrat b3("Alice", 40);
        b3.signForm(f6);
        
        
        Form f7(f6);
        std::cout << "Original: " << f6 << std::endl;
        std::cout << "Copy: " << f7 << std::endl;
        
        
        Form f8;
        f8 = f6;
        std::cout << "Assigned: " << f8 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
