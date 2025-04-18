#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

int main() {
    
    std::cout << "=== Testing with the provided example ===" << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    
    
    std::cout << "\n=== Testing with a full span ===" << std::endl;
    {
        Span sp = Span(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        
        try {
            std::cout << "Trying to add a number to a full span..." << std::endl;
            sp.addNumber(4);
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    
    
    std::cout << "\n=== Testing with not enough numbers ===" << std::endl;
    {
        Span sp = Span(5);
        
        try {
            std::cout << "Trying to find spans with no numbers..." << std::endl;
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        
        try {
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        
        sp.addNumber(42);
        
        try {
            std::cout << "\nTrying to find spans with only one number..." << std::endl;
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        
        try {
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    
    
    std::cout << "\n=== Testing with a large number of elements using addRange ===" << std::endl;
    {
        
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        
        
        Span sp = Span(10000);
        
        
        std::list<int> randomNumbers;
        for (int i = 0; i < 10000; ++i) {
            randomNumbers.push_back(std::rand() % 1000000);
        }
        
        
        sp.addRange(randomNumbers.begin(), randomNumbers.end());
        
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    
    
    std::cout << "\n=== Testing addRange with too many elements ===" << std::endl;
    {
        Span sp = Span(5);
        std::vector<int> numbers;
        numbers.push_back(1);
        numbers.push_back(2);
        numbers.push_back(3);
        numbers.push_back(4);
        numbers.push_back(5);
        numbers.push_back(6);
        
        try {
            std::cout << "Trying to add a range that would exceed the maximum size..." << std::endl;
            sp.addRange(numbers.begin(), numbers.end());
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    
    return 0;
}
