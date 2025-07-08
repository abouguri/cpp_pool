#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request", 72, 45), target("default") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
    : AForm("Robotomy Request", 72, 45), target(target) {
    std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
    : AForm(other), target(other.target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    std::cout << "* DRILLING NOISES * Bzzz... Whirr... Clank!" << std::endl;

    std::srand(std::time(NULL));
    
    if (std::rand() % 2) {
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy of " << this->target << " has failed." << std::endl;
    }
}