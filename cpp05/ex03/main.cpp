#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    std::cout << "---- Testing Intern Class ----" << std::endl;
    try {
        Intern someRandomIntern;
        
        Bureaucrat boss("Big Boss", 1);
        
        std::cout << "\n--- Creating Robotomy Request Form ---\n" << std::endl;
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
        
        std::cout << "\n--- Creating Shrubbery Creation Form ---\n" << std::endl;
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf;
        
        std::cout << "\n--- Creating Presidential Pardon Form ---\n" << std::endl;
        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        delete ppf;
        
        std::cout << "\n--- Creating Unknown Form (should fail) ---\n" << std::endl;
        AForm* unknown = someRandomIntern.makeForm("coffee making", "Kitchen");
        boss.signForm(*unknown);
        boss.executeForm(*unknown);
        delete unknown;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n---- Testing Case Insensitivity ----" << std::endl;
    try {
        Intern intern;
        Bureaucrat chief("Chief", 1);
        
        AForm* form = intern.makeForm("RoBOtoMy ReQuEsT", "Flexo");
        chief.signForm(*form);
        chief.executeForm(*form);
        delete form;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n---- Testing Intern Copying ----" << std::endl;
    try {
        Intern original;
        Intern copy(original);
        Intern assigned;
        assigned = original;
        
        Bureaucrat official("Official", 1);
        
        AForm* form1 = original.makeForm("presidential pardon", "Subject1");
        AForm* form2 = copy.makeForm("robotomy request", "Subject2");
        AForm* form3 = assigned.makeForm("shrubbery creation", "Subject3");
        
        official.signForm(*form1);
        official.executeForm(*form1);
        
        official.signForm(*form2);
        official.executeForm(*form2);
        
        official.signForm(*form3);
        official.executeForm(*form3);
        
        delete form1;
        delete form2;
        delete form3;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}