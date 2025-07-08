#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "---- Testing ShrubberyCreationForm ----" << std::endl;
    try {
        Bureaucrat lowGrade("Intern", 140);
        Bureaucrat midGrade("Manager", 50);
        Bureaucrat highGrade("CEO", 1);

        ShrubberyCreationForm shrubForm("garden");

        std::cout << "Attempting to execute without signing:" << std::endl;
        highGrade.executeForm(shrubForm);

        std::cout << "Signing the form:" << std::endl;
        lowGrade.signForm(shrubForm);

        std::cout << "Executing with different bureaucrats:" << std::endl;
        lowGrade.executeForm(shrubForm);
        midGrade.executeForm(shrubForm);
        highGrade.executeForm(shrubForm);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---- Testing RobotomyRequestForm ----" << std::endl;
    try {
        Bureaucrat lowGrade("Assistant", 100);
        Bureaucrat midGrade("Supervisor", 40);
        Bureaucrat highGrade("Director", 1);

        RobotomyRequestForm robotForm("Bender");

        std::cout << "Attempting to execute without signing:" << std::endl;
        highGrade.executeForm(robotForm);

        std::cout << "Signing with low grade:" << std::endl;
        lowGrade.signForm(robotForm);

        std::cout << "Signing with mid grade:" << std::endl;
        midGrade.signForm(robotForm);

        std::cout << "Executing with different bureaucrats:" << std::endl;
        lowGrade.executeForm(robotForm);
        midGrade.executeForm(robotForm);
        highGrade.executeForm(robotForm);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---- Testing PresidentialPardonForm ----" << std::endl;
    try {
        Bureaucrat lowGrade("Clerk", 100);
        Bureaucrat midGrade("Minister", 20);
        Bureaucrat highGrade("President", 1);

        PresidentialPardonForm pardonForm("Arthur Dent");

        std::cout << "Attempting to execute without signing:" << std::endl;
        highGrade.executeForm(pardonForm);

        std::cout << "Signing with low grade:" << std::endl;
        lowGrade.signForm(pardonForm);

        std::cout << "Signing with mid grade:" << std::endl;
        midGrade.signForm(pardonForm);

        std::cout << "Executing with different bureaucrats:" << std::endl;
        lowGrade.executeForm(pardonForm);
        midGrade.executeForm(pardonForm);
        highGrade.executeForm(pardonForm);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---- Testing Form Copying ----" << std::endl;
    try {
        ShrubberyCreationForm original("backyard");
        Bureaucrat boss("Boss", 1);

        boss.signForm(original);

        ShrubberyCreationForm copy(original);

        std::cout << "Original form: " << original << std::endl;
        std::cout << "Copied form: " << copy << std::endl;

        boss.executeForm(original);
        boss.executeForm(copy);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}