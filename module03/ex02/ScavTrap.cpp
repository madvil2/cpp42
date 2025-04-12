#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap constructor called for " << this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
    }
    return *this;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap destructor called for " << this->_name << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->_energyPoints <= 0) {
        std::cout << "ScavTrap " << this->_name << " is out of energy and cannot attack!" << std::endl;
        return;
    }
    
    if (this->_hitPoints <= 0) {
        std::cout << "ScavTrap " << this->_name << " is out of hit points and cannot attack!" << std::endl;
        return;
    }
    
    std::cout << "ScavTrap " << this->_name << " attacks " << target 
              << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    
    this->_energyPoints--;
}

void ScavTrap::guardGate(void) {
    if (this->_hitPoints <= 0) {
        std::cout << "ScavTrap " << this->_name << " is knocked out and cannot guard the gate!" << std::endl;
        return;
    }
    
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}
