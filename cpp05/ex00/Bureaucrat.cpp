#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : name("Default"), grade(150) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

// Assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &other) {
        // Note: name is const, so we can't reassign it
        // const_cast would be a bad practice here
        // We'll just copy the grade
        this->grade = other.grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

// Getters
std::string Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

// Grade modification
void Bureaucrat::incrementGrade() {
    if (this->grade <= 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->grade >= 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade++;
}

// Exception implementations
const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high, cannot exceed grade 1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low, cannot be below grade 150";
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}