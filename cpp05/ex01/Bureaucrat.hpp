#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration to avoid circular dependency
class Form;

class Bureaucrat {
private:
    const std::string name;
    int grade; // 1 (highest) to 150 (lowest)

public:
    // Orthodox Canonical Form
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    // Getters
    std::string getName() const;
    int getGrade() const;

    // Grade modification
    void incrementGrade();
    void decrementGrade();

    // Form interaction
    void signForm(Form &form);

    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

// Insertion operator overload
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#include "Form.hpp" // Include after Bureaucrat class declaration

#endif