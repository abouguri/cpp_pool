#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap {
protected:
    std::string     _name;
    unsigned int    _hitPoints;
    unsigned int    _energyPoints;
    unsigned int    _attackDamage;

public:
    // Orthodox Canonical Form
    ClapTrap(void);                           // Default constructor
    ClapTrap(const std::string& name);        // Parameterized constructor
    ClapTrap(const ClapTrap& src);            // Copy constructor
    ClapTrap& operator=(const ClapTrap& rhs); // Copy assignment operator
    ~ClapTrap(void);                          // Destructor
    
    // Required member functions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    // Getters
    std::string getName(void) const;
    unsigned int getHitPoints(void) const;
    unsigned int getEnergyPoints(void) const;
    unsigned int getAttackDamage(void) const;
};

#endif