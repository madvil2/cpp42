#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
    std::cout << "Dog constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*src.brain);
}

Dog &Dog::operator=(const Dog &rhs) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &rhs) {
        Animal::operator=(rhs);

        delete this->brain;
        this->brain = new Brain(*rhs.brain);
    }
    return *this;
}

Dog::~Dog(void) {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound(void) const {
    std::cout << "Woof! Woof!" << std::endl;
}

std::string Dog::getBrainIdea(int index) const {
    return this->brain->getIdea(index);
}

void Dog::setBrainIdea(int index, std::string idea) {
    this->brain->setIdea(index, idea);
}
