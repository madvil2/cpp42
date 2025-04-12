#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->_name = rhs.getName();
        this->_hitPoints = rhs.getHitPoints();
        this->_energyPoints = rhs.getEnergyPoints();
        this->_attackDamage = rhs.getAttackDamage();
    }
    return *this;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap destructor called for " << this->_name << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (this->_energyPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " is out of energy and cannot attack!" << std::endl;
        return;
    }
    
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " is out of hit points and cannot attack!" << std::endl;
        return;
    }
    
    std::cout << "ClapTrap " << this->_name << " attacks " << target 
              << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    
    this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " is already knocked out and cannot take more damage!" << std::endl;
        return;
    }
    
    this->_hitPoints -= amount;
    
    std::cout << "ClapTrap " << this->_name << " takes " << amount 
              << " points of damage, reducing hit points to " << this->_hitPoints << "!" << std::endl;
    
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " has been knocked out!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " is out of energy and cannot repair itself!" << std::endl;
        return;
    }
    
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " is knocked out and cannot repair itself!" << std::endl;
        return;
    }
    
    this->_hitPoints += amount;
    this->_energyPoints--;
    
    std::cout << "ClapTrap " << this->_name << " repairs itself, recovering " 
              << amount << " hit points. Now at " << this->_hitPoints << " hit points!" << std::endl;
}

std::string ClapTrap::getName(void) const {
    return this->_name;
}

int ClapTrap::getHitPoints(void) const {
    return this->_hitPoints;
}

int ClapTrap::getEnergyPoints(void) const {
    return this->_energyPoints;
}

int ClapTrap::getAttackDamage(void) const {
    return this->_attackDamage;
}
