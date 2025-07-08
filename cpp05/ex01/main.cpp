#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "---- Test 1: Create Forms with Valid Grades ----" << std::endl;
    try {
        Form f1("Tax Form", 50, 25);
        std::cout << f1 << std::endl;

        Form f2("Security Clearance", 5, 2);
        std::cout << f2 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---- Test 2: Create Form with Invalid Grade (Too High) ----" << std::endl;
    try {
        Form f3("Invalid Form", 0, 10);
        std::cout << f3 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---- Test 3: Create Form with Invalid Grade (Too Low) ----" << std::endl;
    try {
        Form f4("Another Invalid Form", 10, 151);
        std::cout << f4 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---- Test 4: Bureaucrat Signs a Form Successfully ----" << std::endl;
    try {
        Bureaucrat b1("Alice", 30);
        Form f5("Simple Permit", 50, 40);
        
        std::cout << "Before signing: " << f5 << std::endl;
        b1.signForm(f5);
        std::cout << "After signing: " << f5 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---- Test 5: Bureaucrat Fails to Sign a Form (Grade Too Low) ----" << std::endl;
    try {
        Bureaucrat b2("Bob", 75);
        Form f6("Complex Permit", 30, 20);
        
        std::cout << "Before signing attempt: " << f6 << std::endl;
        b2.signForm(f6);
        std::cout << "After signing attempt: " << f6 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---- Test 6: Form Copy Constructor and Assignment Operator ----" << std::endl;
    try {
        Form f7("Original Form", 100, 90);
        Form f7Copy(f7);
        
        Bureaucrat b3("Charlie", 50);
        b3.signForm(f7);
        
        std::cout << "Original after signing: " << f7 << std::endl;
        std::cout << "Copy before signing: " << f7Copy << std::endl;
        
        Form f7Assigned;
        f7Assigned = f7;
        std::cout << "Assigned form: " << f7Assigned << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---- Test 7: Sign an Already Signed Form ----" << std::endl;
    try {
        Form f8("Vacation Request", 100, 100);
        Bureaucrat b4("Diana", 80);
        
        std::cout << "First signing:" << std::endl;
        b4.signForm(f8);
        
        std::cout << "Second signing:" << std::endl;
        b4.signForm(f8);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}