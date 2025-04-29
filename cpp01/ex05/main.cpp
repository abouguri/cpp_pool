#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;
    
    std::cout << "Testing Harl's complaints at different levels:" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Calling DEBUG level:" << std::endl;
    harl.complain("DEBUG");
    
    std::cout << "Calling INFO level:" << std::endl;
    harl.complain("INFO");
    
    std::cout << "Calling WARNING level:" << std::endl;
    harl.complain("WARNING");
    
    std::cout << "Calling ERROR level:" << std::endl;
    harl.complain("ERROR");
    
    std::cout << "Calling an invalid level:" << std::endl;
    harl.complain("CRITICAL");
    
    return 0;
}