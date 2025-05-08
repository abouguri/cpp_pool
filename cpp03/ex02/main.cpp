#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
    std::cout << "======= CLAPTRAP TESTS =======" << std::endl;
    ClapTrap clap("CL4P-TP");
    clap.attack("Bandit");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    std::cout << "\n======= SCAVTRAP TESTS =======" << std::endl;
    ScavTrap scav("SC4V-TP");
    scav.attack("Psycho");
    scav.takeDamage(30);
    scav.beRepaired(15);
    scav.guardGate();
    
    std::cout << "\n======= FRAGTRAP TESTS =======" << std::endl;
    FragTrap frag("FR4G-TP");
    
    // Show different starting values
    std::cout << "FragTrap " << frag.getName() << " has " << frag.getHitPoints() 
              << " hit points, " << frag.getEnergyPoints() << " energy points, and " 
              << frag.getAttackDamage() << " attack damage" << std::endl;
    
    // Test FragTrap-specific behavior
    frag.attack("Loader Bot");
    frag.takeDamage(20);
    frag.beRepaired(10);
    frag.highFivesGuys();
    
    // Test inheritance of functionality
    frag.takeDamage(40);
    frag.beRepaired(20);
    
    // Test copy functionality
    FragTrap frag2(frag);
    frag2.attack("Super Badass");
    
    // Test assignment
    FragTrap frag3;
    frag3 = frag;
    frag3.highFivesGuys();
    
    std::cout << "\n======= CONSTRUCTION/DESTRUCTION CHAINING DEMONSTRATION =======" << std::endl;
    {
        std::cout << "\nCreating a new FragTrap to demonstrate construction order:" << std::endl;
        FragTrap demoFrag("DemoFrag");
        std::cout << "DemoFrag's lifetime ends now, showing destruction order:" << std::endl;
    } // demoFrag goes out of scope here
    
    std::cout << "\nEnd of main function, all objects will be destroyed" << std::endl;
    return 0;
}