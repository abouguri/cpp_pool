#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    // Orthodox Canonical Form
    FragTrap(void);                           // Default constructor
    FragTrap(const std::string& name);        // Parameterized constructor
    FragTrap(const FragTrap& src);            // Copy constructor
    FragTrap& operator=(const FragTrap& rhs); // Copy assignment operator
    ~FragTrap(void);                          // Destructor
    
    // Override attack function (optional but consistent with ScavTrap)
    void attack(const std::string& target);
    
    // Special function
    void highFivesGuys(void);
};

#endif