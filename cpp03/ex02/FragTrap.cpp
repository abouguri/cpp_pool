#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap(void) : ClapTrap() {
    std::cout << "FragTrap default constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

// Parameterized constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "FragTrap constructor called for " << _name << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

// Copy assignment operator
FragTrap& FragTrap::operator=(const FragTrap& rhs) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
    }
    return *this;
}

// Destructor
FragTrap::~FragTrap(void) {
    std::cout << "FragTrap destructor called for " << _name << std::endl;
}

// Override attack function
void FragTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "FragTrap " << _name << " attacks " << target 
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    } else if (_energyPoints == 0) {
        std::cout << "FragTrap " << _name << " has no energy points left to attack!" << std::endl;
    } else {
        std::cout << "FragTrap " << _name << " is too damaged to attack!" << std::endl;
    }
}

// Special highFivesGuys function
void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " enthusiastically requests high fives from everyone! ✋" << std::endl;
}