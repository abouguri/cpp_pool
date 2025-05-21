#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request", 72, 45), target("default") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
    : AForm("Robotomy Request", 72, 45), target(target) {
    std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
    : AForm(other), target(other.target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

// Assignment operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// Execute function
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    // Check if the form is signed and if the executor's grade is high enough
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    // Drilling noises
    std::cout << "* DRILLING NOISES * Bzzz... Whirr... Clank!" << std::endl;

    // Seed the random number generator
    std::srand(std::time(NULL));
    
    // 50% chance of success
    if (std::rand() % 2) {
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy of " << this->target << " has failed." << std::endl;
    }
}