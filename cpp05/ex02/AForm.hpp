#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration to avoid circular dependency
class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    // Orthodox Canonical Form
    AForm();
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    // Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Member functions
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0; // Pure virtual function

    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

// Insertion operator overload
std::ostream &operator<<(std::ostream &os, const AForm &form);

#include "Bureaucrat.hpp" // Include after AForm class declaration

#endif