#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    std::vector<int> v;
    for (int i = 0; i < 5; ++i)
        v.push_back(i * 2);

    try {
        std::vector<int>::iterator it = easyfind(v, 4);
        std::cout << "Found 4 in vector at index: " << std::distance(v.begin(), it) << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        easyfind(v, 7);
    } catch (const std::exception &e) {
        std::cout << "Looking for 7: " << e.what() << std::endl;
    }

    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    try {
        std::list<int>::iterator it = easyfind(l, 10);
        std::cout << "Found: " << *it << "in list" << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        easyfind(l, 99);
    } catch (const std::exception &e) {
        std::cout << "Looking for 99: " << e.what() << std::endl;
    }

    return 0;
}