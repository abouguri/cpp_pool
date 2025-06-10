#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "---- Test 1: Valid Bureaucrat Creation ----" << std::endl;
    try {
        Bureaucrat b1("John", 50);
        std::cout << b1 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---- Test 2: Grade Too High ----" << std::endl;
    try {
        Bureaucrat b2("Alice", 0);
        std::cout << b2 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---- Test 3: Grade Too Low ----" << std::endl;
    try {
        Bureaucrat b3("Bob", 151);
        std::cout << b3 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---- Test 4: Increment Grade ----" << std::endl;
    try {
        Bureaucrat b4("Charlie", 10);
        std::cout << "Before increment: " << b4 << std::endl;
        b4.incrementGrade();
        std::cout << "After increment: " << b4 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---- Test 5: Decrement Grade ----" << std::endl;
    try {
        Bureaucrat b5("Diana", 140);
        std::cout << "Before decrement: " << b5 << std::endl;
        b5.decrementGrade();
        std::cout << "After decrement: " << b5 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---- Test 6: Increment To Invalid Grade ----" << std::endl;
    try {
        Bureaucrat b6("Eve", 1);
        std::cout << "Before increment: " << b6 << std::endl;
        b6.incrementGrade(); // This should throw an exception
        std::cout << "After increment: " << b6 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---- Test 7: Decrement To Invalid Grade ----" << std::endl;
    try {
        Bureaucrat b7("Frank", 150);
        std::cout << "Before decrement: " << b7 << std::endl;
        b7.decrementGrade(); // This should throw an exception
        std::cout << "After decrement: " << b7 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---- Test 8: Copy Constructor ----" << std::endl;
    try {
        Bureaucrat b8("Grace", 42);
        Bureaucrat b8Copy(b8);
        std::cout << "Original: " << b8 << std::endl;
        std::cout << "Copy: " << b8Copy << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "---- Test 9: Assignment Operator ----" << std::endl;
    try {
        Bureaucrat b9("Harry", 75);
        Bureaucrat b9Assigned;
        b9Assigned = b9;
        std::cout << "Original: " << b9 << std::endl;
        std::cout << "Assigned: " << b9Assigned << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}