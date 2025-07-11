#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";

    std::string* stringPTR = &str;

    std::string& stringREF = str;

    std::cout << "Memory address of the string variable: " << &str << std::endl;

    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;

    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "Value of the string variable: " << str << std::endl;

    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;

    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return (0);
}
