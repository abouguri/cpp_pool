#include "ClapTrap.hpp"

int main(void) {
    // Test constructor
    ClapTrap clap1("CL4P-TP");
    
    // Test attacks
    clap1.attack("Bandit");
    
    // Test taking damage
    clap1.takeDamage(5);
    
    // Test repairs
    clap1.beRepaired(3);
    
    // Test taking lethal damage
    clap1.takeDamage(10);
    
    // Test actions when destroyed
    clap1.attack("Skag");
    clap1.beRepaired(5);
    
    // Test copy constructor
    ClapTrap clap2(clap1);
    
    // Test assignment operator
    ClapTrap clap3;
    clap3 = clap1;
    
    // Test energy depletion
    ClapTrap clap4("Energetic");
    for (int i = 0; i < 10; i++) {
        clap4.attack("Target");
    }
    // Should be out of energy now
    clap4.attack("Target");
    clap4.beRepaired(1);
    
    return 0;
}