
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Array.hpp"

int main() {
    try {
        Array<int> empty;
        std::cout << "Empty array size: " << empty.size() << std::endl;

        Array<int> numbers(5);
        std::cout << "Numbers array size: " << numbers.size() << std::endl;
        for (unsigned int i = 0; i < numbers.size(); ++i)
            numbers[i] = i * 10;
        for (unsigned int i = 0; i < numbers.size(); ++i)
            std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

        Array<int> copy(numbers);
        std::cout << "Copy array size: " << copy.size() << std::endl;
        for (unsigned int i = 0; i < copy.size(); ++i)
            std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
        copy[0] = 999;
        std::cout << "After modify copy[0], numbers[0] = " << numbers[0] << std::endl;

        Array<int> assign;
        assign = numbers;
        std::cout << "Assign array size: " << assign.size() << std::endl;
        assign[1] = 888;
        std::cout << "After modify assign[1], numbers[1] = " << numbers[1] << std::endl;

        std::cout << "Testing out-of-bounds access..." << std::endl;
        std::cout << numbers[numbers.size()] << std::endl; // Should throw

    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}


// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }