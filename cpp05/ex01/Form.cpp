#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default constructor
Form::Form() : name("Default Form"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    std::cout << "Form default constructor called" << std::endl;
}

// Parameterized constructor
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) 
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    std::cout << "Form parameterized constructor called" << std::endl;
    
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw Form::GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw Form::GradeTooLowException();
    }
}

// Copy constructor
Form::Form(const Form &other) 
    : name(other.name), isSigned(other.isSigned), 
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    std::cout << "Form copy constructor called" << std::endl;
}

// Assignment operator
Form &Form::operator=(const Form &other) {
    std::cout << "Form assignment operator called" << std::endl;
    if (this != &other) {
        // Cannot assign to const members
        // Assign only the non-const member
        this->isSigned = other.isSigned;
    }
    return *this;
}

// Destructor
Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

// Getters
std::string Form::getName() const {
    return this->name;
}

bool Form::getIsSigned() const {
    return this->isSigned;
}

int Form::getGradeToSign() const {
    return this->gradeToSign;
}

int Form::getGradeToExecute() const {
    return this->gradeToExecute;
}

// Member functions
void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= this->gradeToSign) {
        this->isSigned = true;
    } else {
        throw Form::GradeTooLowException();
    }
}

// Exception implementations
const char *Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high, cannot exceed grade 1";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low, cannot be below grade 150";
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Form: " << form.getName() 
       << ", signed: " << (form.getIsSigned() ? "yes" : "no") 
       << ", grade to sign: " << form.getGradeToSign() 
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
}