#include <iostream>
#include "functions.hpp"

int main() {
    // Test with several random objects
    for (int i = 0; i < 10; ++i) {
        Base* ptr = generate();
        std::cout << "identify(Base*): ";
        identify(ptr);
        std::cout << "identify(Base&): ";
        identify(*ptr);
        delete ptr;
        std::cout << "---" << std::endl;
    }
    return 0;
}