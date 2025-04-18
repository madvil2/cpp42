#include "Array.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

int main() {
    
    std::cout << "=== Testing with the provided example ===" << std::endl;
    {
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++) {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        
        
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        
        for (int i = 0; i < MAX_VAL; i++) {
            if (mirror[i] != numbers[i]) {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        
        
        try {
            numbers[-2] = 0;
        } catch(const std::exception& e) {
            std::cerr << "Exception caught: Negative index" << std::endl;
        }
        
        try {
            numbers[MAX_VAL] = 0;
        } catch(const std::exception& e) {
            std::cerr << "Exception caught: Index too large" << std::endl;
        }

        
        for (int i = 0; i < MAX_VAL; i++) {
            numbers[i] = rand();
        }
        
        delete [] mirror;
    }
    
    
    std::cout << "\n=== Testing with empty array ===" << std::endl;
    {
        
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;
        
        try {
            std::cout << "Trying to access element 0 of empty array..." << std::endl;
            emptyArray[0] = 42;
        } catch(const std::exception& e) {
            std::cerr << "Exception caught: Index out of bounds" << std::endl;
        }
    }
    
    std::cout << "\n=== Testing with array of strings ===" << std::endl;
    {
        
        Array<std::string> stringArray(5);
        stringArray[0] = "Hello";
        stringArray[1] = "World";
        stringArray[2] = "C++";
        stringArray[3] = "Templates";
        stringArray[4] = "Array";
        
        std::cout << "String array contents:" << std::endl;
        for (unsigned int i = 0; i < stringArray.size(); ++i) {
            std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
        }
        
        
        Array<std::string> stringArrayCopy(stringArray);
        std::cout << "\nCopied string array contents:" << std::endl;
        for (unsigned int i = 0; i < stringArrayCopy.size(); ++i) {
            std::cout << "stringArrayCopy[" << i << "] = " << stringArrayCopy[i] << std::endl;
        }
        
        
        stringArray[2] = "Modified";
        std::cout << "\nAfter modifying the original array:" << std::endl;
        std::cout << "Original: stringArray[2] = " << stringArray[2] << std::endl;
        std::cout << "Copy: stringArrayCopy[2] = " << stringArrayCopy[2] << std::endl;
    }
    
    std::cout << "\n=== Testing with const array ===" << std::endl;
    {
        
        const Array<int> constArray(3);
        
        
        
        try {
            std::cout << "constArray[0] = " << constArray[0] << std::endl;
            std::cout << "constArray[1] = " << constArray[1] << std::endl;
            std::cout << "constArray[2] = " << constArray[2] << std::endl;
            std::cout << "constArray size: " << constArray.size() << std::endl;
        } catch(const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }
    
    return 0;
}
