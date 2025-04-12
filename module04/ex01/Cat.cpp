#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
    std::cout << "Cat constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal(src) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain(*src.brain);
}

Cat &Cat::operator=(const Cat &rhs) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &rhs) {
        Animal::operator=(rhs);

        delete this->brain;
        this->brain = new Brain(*rhs.brain);
    }
    return *this;
}

Cat::~Cat(void) {
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

void Cat::makeSound(void) const {
    std::cout << "Meow! Meow!" << std::endl;
}

std::string Cat::getBrainIdea(int index) const {
    return this->brain->getIdea(index);
}

void Cat::setBrainIdea(int index, std::string idea) {
    this->brain->setIdea(index, idea);
}
