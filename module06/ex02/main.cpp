#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>


Base* generate(void) {

    int random = std::rand() % 3;


    switch (random) {
        case 0:
            std::cout << "Generated an instance of A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated an instance of B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated an instance of C" << std::endl;
            return new C();
        default:
            return NULL;
    }
}


void identify(Base* p) {

    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}


void identify(Base& p) {


    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast&) {

    }

    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast&) {

    }

    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    } catch (std::bad_cast&) {

        std::cout << "Unknown type" << std::endl;
    }
}

int main() {

    std::srand(static_cast<unsigned int>(std::time(NULL)));


    std::cout << "=== Testing generate function ===" << std::endl;
    Base* ptr1 = generate();
    Base* ptr2 = generate();
    Base* ptr3 = generate();


    std::cout << "\n=== Testing identify function with pointers ===" << std::endl;
    std::cout << "ptr1 is of type: ";
    identify(ptr1);
    std::cout << "ptr2 is of type: ";
    identify(ptr2);
    std::cout << "ptr3 is of type: ";
    identify(ptr3);


    std::cout << "\n=== Testing identify function with references ===" << std::endl;
    std::cout << "ptr1 is of type: ";
    identify(*ptr1);
    std::cout << "ptr2 is of type: ";
    identify(*ptr2);
    std::cout << "ptr3 is of type: ";
    identify(*ptr3);


    delete ptr1;
    delete ptr2;
    delete ptr3;

    return 0;
}
