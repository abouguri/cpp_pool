#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "---- Testing ShrubberyCreationForm ----" << std::endl;
    try {
        // Create bureaucrats
        Bureaucrat lowGrade("Intern", 140);
        Bureaucrat midGrade("Manager", 50);
        Bureaucrat highGrade("CEO", 1);
        
        // Create form
        ShrubberyCreationForm shrubForm("garden");
        
        // Attempt to execute without signing
        std::cout << "Attempting to execute without signing:" << std::endl;
        highGrade.executeForm(shrubForm);
        
        // Sign the form
        std::cout << "Signing the form:" << std::endl;
        lowGrade.signForm(shrubForm);
        
        // Execute the form with different bureaucrats
        std::cout << "Executing with different bureaucrats:" << std::endl;
        lowGrade.executeForm(shrubForm);  // Should succeed
        midGrade.executeForm(shrubForm);  // Should succeed
        highGrade.executeForm(shrubForm); // Should succeed
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "---- Testing RobotomyRequestForm ----" << std::endl;
    try {
        // Create bureaucrats
        Bureaucrat lowGrade("Assistant", 100);
        Bureaucrat midGrade("Supervisor", 40);
        Bureaucrat highGrade("Director", 1);
        
        // Create form
        RobotomyRequestForm robotForm("Bender");
        
        // Attempt to execute without signing
        std::cout << "Attempting to execute without signing:" << std::endl;
        highGrade.executeForm(robotForm);
        
        // Sign the form - should fail with low grade
        std::cout << "Signing with low grade:" << std::endl;
        lowGrade.signForm(robotForm);
        
        // Sign the form - should succeed with mid grade
        std::cout << "Signing with mid grade:" << std::endl;
        midGrade.signForm(robotForm);
        
        // Execute the form with different bureaucrats
        std::cout << "Executing with different bureaucrats:" << std::endl;
        lowGrade.executeForm(robotForm);  // Should fail
        midGrade.executeForm(robotForm);  // Should succeed
        highGrade.executeForm(robotForm); // Should succeed
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "---- Testing PresidentialPardonForm ----" << std::endl;
    try {
        // Create bureaucrats
        Bureaucrat lowGrade("Clerk", 100);
        Bureaucrat midGrade("Minister", 20);
        Bureaucrat highGrade("President", 1);
        
        // Create form
        PresidentialPardonForm pardonForm("Arthur Dent");
        
        // Attempt to execute without signing
        std::cout << "Attempting to execute without signing:" << std::endl;
        highGrade.executeForm(pardonForm);
        
        // Sign the form - should fail with low grade
        std::cout << "Signing with low grade:" << std::endl;
        lowGrade.signForm(pardonForm);
        
        // Sign the form - should succeed with mid grade
        std::cout << "Signing with mid grade:" << std::endl;
        midGrade.signForm(pardonForm);
        
        // Execute the form with different bureaucrats
        std::cout << "Executing with different bureaucrats:" << std::endl;
        lowGrade.executeForm(pardonForm);  // Should fail
        midGrade.executeForm(pardonForm);  // Should fail
        highGrade.executeForm(pardonForm); // Should succeed
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "---- Testing Form Copying ----" << std::endl;
    try {
        // Create original form and bureaucrat
        ShrubberyCreationForm original("backyard");
        Bureaucrat boss("Boss", 1);
        
        // Sign the original form
        boss.signForm(original);
        
        // Create a copy using copy constructor
        ShrubberyCreationForm copy(original);
        
        // Check if the copy is also signed
        std::cout << "Original form: " << original << std::endl;
        std::cout << "Copied form: " << copy << std::endl;
        
        // Execute both forms
        boss.executeForm(original);
        boss.executeForm(copy);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}