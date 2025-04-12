#include "Animal.hpp"

Animal::Animal(void) : type("Abstract Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
    std::cout << "Animal parametrized constructor called" << std::endl;
}

Animal::Animal(const Animal &src) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal &Animal::operator=(const Animal &rhs) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

Animal::~Animal(void) {
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const {
    return this->type;
}
