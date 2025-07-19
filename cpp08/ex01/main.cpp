#include <iostream>
#include "Span.hpp"
#include <vector>
#include <cstdlib>

int main() {
    {
        std::cout << "Basic test:" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    {
        std::cout << "\nTest with 10000 numbers:" << std::endl;
        Span big(10000);
        for (int i = 0; i < 10000; ++i)
            big.addNumber(rand());
        std::cout << "Shortest: " << big.shortestSpan() << std::endl;
        std::cout << "Longest: " << big.longestSpan() << std::endl;
    }

    {
        std::cout << "\nTest with range of iterators:" << std::endl;
        std::vector<int> v;
        for (int i = 0; i < 100; ++i)
            v.push_back(i * 10);
        Span s(100);
        s.addNumbers(v.begin(), v.end());
        std::cout << "Shortest: " << s.shortestSpan() << std::endl;
        std::cout << "Longest: " << s.longestSpan() << std::endl;
    }

    {
        std::cout << "\nException tests:" << std::endl;
        Span s(2);
        try {
            s.addNumber(1);
            s.addNumber(2);
            s.addNumber(3);
        } catch (const std::exception& e) {
            std::cout << "Caught: " << e.what() << std::endl;
        }
        try {
            Span s2(1);
            s2.addNumber(42);
            std::cout << s2.shortestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Caught: " << e.what() << std::endl;
        }
    }

    return 0;
}