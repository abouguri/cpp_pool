#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap constructor called for " << _name << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& src) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = src;
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &rhs) {
        _name = rhs._name;
        _hitPoints = rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    return *this;
}

// Destructor
ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

// Attack function
void ClapTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target 
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    } else if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no energy points left to attack!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " is too damaged to attack!" << std::endl;
    }
}

// Take damage function
void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints > 0) {
        if (amount >= _hitPoints) {
            _hitPoints = 0;
            std::cout << "ClapTrap " << _name << " takes " << amount 
                      << " damage and is destroyed!" << std::endl;
        } else {
            _hitPoints -= amount;
            std::cout << "ClapTrap " << _name << " takes " << amount 
                      << " damage! Remaining hit points: " << _hitPoints << std::endl;
        }
    } else {
        std::cout << "ClapTrap " << _name << " is already destroyed and cannot take more damage!" << std::endl;
    }
}

// Repair function
void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount 
                  << " hit points! Current hit points: " << _hitPoints << std::endl;
        _energyPoints--;
    } else if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no energy points left to repair itself!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " is too damaged to repair itself!" << std::endl;
    }
}

// Getters
std::string ClapTrap::getName(void) const {
    return _name;
}

unsigned int ClapTrap::getHitPoints(void) const {
    return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const {
    return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const {
    return _attackDamage;
}