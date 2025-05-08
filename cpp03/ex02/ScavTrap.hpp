#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    // Orthodox Canonical Form
    ScavTrap(void);                           // Default constructor
    ScavTrap(const std::string& name);        // Parameterized constructor
    ScavTrap(const ScavTrap& src);            // Copy constructor
    ScavTrap& operator=(const ScavTrap& rhs); // Copy assignment operator
    ~ScavTrap(void);                          // Destructor
    
    // Override attack function
    void attack(const std::string& target);
    
    // Special function
    void guardGate(void);
};

#endif