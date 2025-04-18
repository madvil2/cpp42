#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>


template <typename T>
void testEasyfind(T& container, int value, const std::string& containerName) {
    std::cout << "Searching for " << value << " in " << containerName << "..." << std::endl;
    
    try {
        typename T::iterator it = easyfind(container, value);
        std::cout << "Value " << value << " found at position: " 
                  << std::distance(container.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}


template <typename T>
void testEasyfindConst(const T& container, int value, const std::string& containerName) {
    std::cout << "Searching for " << value << " in const " << containerName << "..." << std::endl;
    
    try {
        typename T::const_iterator it = easyfind(container, value);
        std::cout << "Value " << value << " found at position: " 
                  << std::distance(container.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    
    std::cout << "=== Testing with std::vector ===" << std::endl;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    testEasyfind(vec, 3, "vector");
    testEasyfind(vec, 6, "vector");
    
    
    std::cout << "\n=== Testing with std::list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);
    
    testEasyfind(lst, 30, "list");
    testEasyfind(lst, 60, "list");
    
    
    std::cout << "\n=== Testing with std::deque ===" << std::endl;
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    deq.push_back(400);
    deq.push_back(500);
    
    testEasyfind(deq, 300, "deque");
    testEasyfind(deq, 600, "deque");
    
    
    std::cout << "\n=== Testing with const containers ===" << std::endl;
    const std::vector<int> constVec(vec);
    const std::list<int> constLst(lst);
    const std::deque<int> constDeq(deq);
    
    testEasyfindConst(constVec, 3, "vector");
    testEasyfindConst(constLst, 30, "list");
    testEasyfindConst(constDeq, 300, "deque");
    
    return 0;
}
