#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    std::cout << "Intern assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

const char *Intern::FormNotFoundException::what() const throw() {
    return "Form type not found";
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    struct FormType {
        std::string name;
        AForm* (*create)(const std::string&);
    };
    
    FormType forms[] = {
        {"shrubbery creation", createShrubbery},
        {"robotomy request", createRobotomy},
        {"presidential pardon", createPresidential}
    };
    
    std::string lowerFormName = formName;
    for (size_t i = 0; i < formName.length(); ++i) {
        lowerFormName[i] = std::tolower(formName[i]);
    }
    
    for (int i = 0; i < 3; ++i) {
        if (lowerFormName == forms[i].name) {
            AForm* form = forms[i].create(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    
    std::cout << "Intern cannot create form: " << formName << " (unknown type)" << std::endl;
    throw FormNotFoundException();
    return NULL;
}