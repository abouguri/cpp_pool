#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Helper functions for form creation
static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// Default constructor
Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

// Copy constructor
Intern::Intern(const Intern &other) {
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other; // Unused parameter since Intern has no attributes
}

// Assignment operator
Intern &Intern::operator=(const Intern &other) {
    std::cout << "Intern assignment operator called" << std::endl;
    (void)other; // Unused parameter since Intern has no attributes
    return *this;
}

// Destructor
Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

// Exception implementation
const char *Intern::FormNotFoundException::what() const throw() {
    return "Form type not found";
}

// Member function to create a form
AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    // Define form types
    struct FormType {
        std::string name;
        AForm* (*create)(const std::string&);
    };
    
    // Array of form types and their creators
    FormType forms[] = {
        {"shrubbery creation", createShrubbery},
        {"robotomy request", createRobotomy},
        {"presidential pardon", createPresidential}
    };
    
    // Convert formName to lowercase for case-insensitive comparison
    std::string lowerFormName = formName;
    for (size_t i = 0; i < formName.length(); ++i) {
        lowerFormName[i] = std::tolower(formName[i]);
    }
    
    // Find matching form and create it
    for (int i = 0; i < 3; ++i) {
        if (lowerFormName == forms[i].name) {
            AForm* form = forms[i].create(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    
    // If no matching form found, throw exception
    std::cout << "Intern cannot create form: " << formName << " (unknown type)" << std::endl;
    throw FormNotFoundException();
    return NULL;
}