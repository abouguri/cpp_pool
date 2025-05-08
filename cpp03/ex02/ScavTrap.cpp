#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap(void) : ClapTrap() {
    std::cout << "ScavTrap default constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

// Parameterized constructor
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "ScavTrap constructor called for " << _name << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

// Copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
    }
    return *this;
}

// Destructor
ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

// Override attack function
void ScavTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "ScavTrap " << _name << " attacks " << target 
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    } else if (_energyPoints == 0) {
        std::cout << "ScavTrap " << _name << " has no energy points left to attack!" << std::endl;
    } else {
        std::cout << "ScavTrap " << _name << " is too damaged to attack!" << std::endl;
    }
}

// Special guardGate function
void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}