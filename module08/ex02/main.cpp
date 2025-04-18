#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>


void testMutantStack() {
    std::cout << "=== Testing with MutantStack ===" << std::endl;
    
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "Elements (from bottom to top):" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    
    std::cout << "\nTesting copy constructor:" << std::endl;
    MutantStack<int> mstack_copy(mstack);
    std::cout << "Copy size: " << mstack_copy.size() << std::endl;
    std::cout << "Copy top: " << mstack_copy.top() << std::endl;
    
    
    std::cout << "\nTesting assignment operator:" << std::endl;
    MutantStack<int> mstack_assigned;
    mstack_assigned = mstack;
    std::cout << "Assigned size: " << mstack_assigned.size() << std::endl;
    std::cout << "Assigned top: " << mstack_assigned.top() << std::endl;
    
    
    std::cout << "\nTesting conversion to std::stack:" << std::endl;
    std::stack<int> s(mstack);
    std::cout << "std::stack size: " << s.size() << std::endl;
    std::cout << "std::stack top: " << s.top() << std::endl;
    
    
    std::cout << "\nElements (from top to bottom) using reverse iterators:" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    
    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }
}


void testList() {
    std::cout << "\n=== Testing with std::list ===" << std::endl;
    
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    
    std::cout << "Top: " << lst.back() << std::endl;
    
    lst.pop_back();
    
    std::cout << "Size: " << lst.size() << std::endl;
    
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::cout << "Elements (from bottom to top):" << std::endl;
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    
    ++it;
    --it;
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
}


void testVector() {
    std::cout << "\n=== Testing with std::vector ===" << std::endl;
    
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(17);
    
    std::cout << "Top: " << vec.back() << std::endl;
    
    vec.pop_back();
    
    std::cout << "Size: " << vec.size() << std::endl;
    
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(737);
    vec.push_back(0);
    
    std::cout << "Elements (from bottom to top):" << std::endl;
    std::vector<int>::iterator it = vec.begin();
    std::vector<int>::iterator ite = vec.end();
    
    ++it;
    --it;
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
}

int main() {
    
    testMutantStack();
    
    
    testList();
    
    
    testVector();
    
    return 0;
}
