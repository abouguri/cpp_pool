#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <exception>

class RPN {
private:
    std::stack<int> _stack;

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int calculate(const std::string& expression);
    bool isOperator(const std::string& token) const;
    void performOperation(const std::string& op);

    class RPNException : public std::exception {
    public:
        virtual const char* what() const throw() { return "Error"; }
    };
};

#endif