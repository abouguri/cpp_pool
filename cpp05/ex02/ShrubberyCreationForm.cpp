#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation", 145, 137), target("default") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
    : AForm("Shrubbery Creation", 145, 137), target(target) {
    std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
    : AForm(other), target(other.target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

// Assignment operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// Execute function
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    // Check if the form is signed and if the executor's grade is high enough
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    // Create the output file
    std::string filename = this->target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    // ASCII trees
    outfile << "      /\\      " << std::endl;
    outfile << "     /\\*\\     " << std::endl;
    outfile << "    /\\O\\*\\    " << std::endl;
    outfile << "   /*/\\/\\/\\   " << std::endl;
    outfile << "  /\\O\\/\\*\\/\\  " << std::endl;
    outfile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    outfile << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    outfile << "      ||      " << std::endl;
    outfile << "      ||      " << std::endl;
    outfile << "      ||      " << std::endl;
    outfile << std::endl;
    outfile << "      /\\      " << std::endl;
    outfile << "     /\\*\\     " << std::endl;
    outfile << "    /\\O\\*\\    " << std::endl;
    outfile << "   /*/\\/\\/\\   " << std::endl;
    outfile << "  /\\O\\/\\*\\/\\  " << std::endl;
    outfile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    outfile << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    outfile << "      ||      " << std::endl;
    outfile << "      ||      " << std::endl;
    outfile << "      ||      " << std::endl;

    outfile.close();
    std::cout << "Created shrubbery in " << filename << std::endl;
}