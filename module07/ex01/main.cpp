#include "iter.hpp"
#include <iostream>
#include <string>


template <typename T>
void printElement(T const & element) {
    std::cout << element << " ";
}


void squareInt(int & element) {
    element = element * element;
}


void toUppercase(char & element) {
    if (element >= 'a' && element <= 'z') {
        element = element - 'a' + 'A';
    }
}

int main() {
    
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(int);
    
    std::cout << "=== Testing with an array of integers ===" << std::endl;
    std::cout << "Original array: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;
    
    
    iter(intArray, intArrayLength, squareInt);
    
    std::cout << "After squaring: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;
    
    
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArrayLength = sizeof(charArray) / sizeof(char);
    
    std::cout << "\n=== Testing with an array of characters ===" << std::endl;
    std::cout << "Original array: ";
    iter(charArray, charArrayLength, printElement<char>);
    std::cout << std::endl;
    
    
    iter(charArray, charArrayLength, toUppercase);
    
    std::cout << "After uppercasing: ";
    iter(charArray, charArrayLength, printElement<char>);
    std::cout << std::endl;
    
    
    std::string stringArray[] = {"Hello", "World", "C++", "Templates", "are", "fun"};
    size_t stringArrayLength = sizeof(stringArray) / sizeof(std::string);
    
    std::cout << "\n=== Testing with an array of strings ===" << std::endl;
    std::cout << "String array: ";
    iter(stringArray, stringArrayLength, printElement<std::string>);
    std::cout << std::endl;
    
    
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArrayLength = sizeof(doubleArray) / sizeof(double);
    
    std::cout << "\n=== Testing with an array of doubles ===" << std::endl;
    std::cout << "Double array: ";
    iter(doubleArray, doubleArrayLength, printElement<double>);
    std::cout << std::endl;
    
    return 0;
}
