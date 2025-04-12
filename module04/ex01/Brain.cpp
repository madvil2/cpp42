#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = "Empty idea";
    }
}

Brain::Brain(const Brain &src) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
}

Brain &Brain::operator=(const Brain &rhs) {
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &rhs) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = rhs.getIdea(i);
        }
    }
    return *this;
}

Brain::~Brain(void) {
    std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return this->ideas[index];
    }
    return "Invalid idea index";
}

void Brain::setIdea(int index, std::string idea) {
    if (index >= 0 && index < 100) {
        this->ideas[index] = idea;
    }
}
