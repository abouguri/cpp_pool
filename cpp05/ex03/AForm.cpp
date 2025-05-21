#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
AForm::AForm() : name("Default Form"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    std::cout << "AForm default constructor called" << std::endl;
}

// Parameterized constructor
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) 
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    std::cout << "AForm parameterized constructor called" << std::endl;
    
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw AForm::GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw AForm::GradeTooLowException();
    }
}

// Copy constructor
AForm::AForm(const AForm &other) 
    : name(other.name), isSigned(other.isSigned), 
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    std::cout << "AForm copy constructor called" << std::endl;
}

// Assignment operator
AForm &AForm::operator=(const AForm &other) {
    std::cout << "AForm assignment operator called" << std::endl;
    if (this != &other) {
        // Cannot assign to const members
        // Assign only the non-const member
        this->isSigned = other.isSigned;
    }
    return *this;
}

// Destructor
AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

// Getters
std::string AForm::getName() const {
    return this->name;
}

bool AForm::getIsSigned() const {
    return this->isSigned;
}

int AForm::getGradeToSign() const {
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->gradeToExecute;
}

// Member functions
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= this->gradeToSign) {
        this->isSigned = true;
    } else {
        throw AForm::GradeTooLowException();
    }
}

// Exception implementations
const char *AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high, cannot exceed grade 1";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low, cannot be below grade 150 or bureaucrat's grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed and cannot be executed";
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << "Form: " << form.getName() 
       << ", signed: " << (form.getIsSigned() ? "yes" : "no") 
       << ", grade to sign: " << form.getGradeToSign() 
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
}