#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "===== Testing Bureaucrat Class =====" << std::endl;

    
    std::cout << "\n----- Test 1: Valid bureaucrat creation -----" << std::endl;
    try {
        Bureaucrat b1("John", 75);
        std::cout << b1 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << "\n----- Test 2: Grade too high exception -----" << std::endl;
    try {
        Bureaucrat b2("Alice", 0);
        std::cout << b2 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << "\n----- Test 3: Grade too low exception -----" << std::endl;
    try {
        Bureaucrat b3("Bob", 151);
        std::cout << b3 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << "\n----- Test 4: Increment grade -----" << std::endl;
    try {
        Bureaucrat b4("Charlie", 10);
        std::cout << "Before increment: " << b4 << std::endl;
        b4.incrementGrade();
        std::cout << "After increment: " << b4 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << "\n----- Test 5: Decrement grade -----" << std::endl;
    try {
        Bureaucrat b5("David", 140);
        std::cout << "Before decrement: " << b5 << std::endl;
        b5.decrementGrade();
        std::cout << "After decrement: " << b5 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << "\n----- Test 6: Increment at boundary -----" << std::endl;
    try {
        Bureaucrat b6("Eve", 1);
        std::cout << "Before increment: " << b6 << std::endl;
        b6.incrementGrade();
        std::cout << "After increment: " << b6 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << "\n----- Test 7: Decrement at boundary -----" << std::endl;
    try {
        Bureaucrat b7("Frank", 150);
        std::cout << "Before decrement: " << b7 << std::endl;
        b7.decrementGrade();
        std::cout << "After decrement: " << b7 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << "\n----- Test 8: Copy constructor and assignment operator -----" << std::endl;
    try {
        Bureaucrat b8("Grace", 42);
        std::cout << "Original: " << b8 << std::endl;
        
        Bureaucrat b9(b8);
        std::cout << "Copy constructed: " << b9 << std::endl;
        
        Bureaucrat b10;
        b10 = b8;
        std::cout << "Assigned: " << b10 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
