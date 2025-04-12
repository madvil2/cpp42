#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap constructor called for " << this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
    }
    return *this;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap destructor called for " << this->_name << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (this->_energyPoints <= 0) {
        std::cout << "FragTrap " << this->_name << " is out of energy and cannot attack!" << std::endl;
        return;
    }
    
    if (this->_hitPoints <= 0) {
        std::cout << "FragTrap " << this->_name << " is out of hit points and cannot attack!" << std::endl;
        return;
    }
    
    std::cout << "FragTrap " << this->_name << " attacks " << target 
              << " with explosive rounds, causing " << this->_attackDamage << " points of damage!" << std::endl;
    
    this->_energyPoints--;
}

void FragTrap::highFivesGuys(void) {
    if (this->_hitPoints <= 0) {
        std::cout << "FragTrap " << this->_name << " is knocked out and cannot request high fives!" << std::endl;
        return;
    }
    
    std::cout << "FragTrap " << this->_name << " enthusiastically requests high fives from everyone! C'mon guys!" << std::endl;
}
