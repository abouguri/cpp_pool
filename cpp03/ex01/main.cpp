#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    std::cout << "==== Testing ClapTrap ====" << std::endl;
    ClapTrap clap("CL4P-TP");
    clap.attack("Bandit");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    std::cout << "\n==== Testing ScavTrap ====" << std::endl;
    ScavTrap scav("SC4V-TP");
    
    // Show different starting values
    std::cout << "ScavTrap " << scav.getName() << " has " << scav.getHitPoints() 
              << " hit points, " << scav.getEnergyPoints() << " energy points, and " 
              << scav.getAttackDamage() << " attack damage" << std::endl;
    
    // Test ScavTrap-specific behavior
    scav.attack("Psycho");
    scav.takeDamage(30);
    scav.beRepaired(15);
    scav.guardGate();
    
    // Test inheritance of functionality
    scav.takeDamage(50);
    scav.beRepaired(10);
    
    // Test copy functionality
    ScavTrap scav2(scav);
    scav2.attack("Nomad");
    
    // Test assignment
    ScavTrap scav3;
    scav3 = scav;
    scav3.guardGate();
    
    std::cout << "\n==== Destruction Order Demonstration ====" << std::endl;
    // Destruction happens automatically at end of scope,
    // this is to demonstrate the order
    
    return 0;
}