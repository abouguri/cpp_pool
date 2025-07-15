#include <iostream>
#include "iter.hpp"

template <typename T>
void print(T& x) {
    std::cout << x << " ";
}

void increment(int& x) {
    ++x;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"42", "Network", "C++", "1337"};
    const double dblArray[] = {1.3, 4.2, 3.7};

    std::cout << "Original intArray: ";
    iter(intArray, 5, print);
    std::cout << std::endl;

    iter(intArray, 5, increment);
    std::cout << "After increment: ";
    iter(intArray, 5, print);
    std::cout << std::endl;

    std::cout << "strArray: ";
    iter(strArray, 4, print);
    std::cout << std::endl;

    std::cout << "dblArray: ";
    iter(dblArray, 3, print);
    std::cout << std::endl;

    return 0;
}