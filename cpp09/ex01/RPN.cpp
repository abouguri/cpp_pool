#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

void RPN::performOperation(const std::string& op) {
    if (_stack.size() < 2) {
        throw RPNException();
    }

    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();

    if (op == "+") {
        _stack.push(a + b);
    } else if (op == "-") {
        _stack.push(a - b);
    } else if (op == "*") {
        _stack.push(a * b);
    } else if (op == "/") {
        if (b == 0) {
            throw RPNException();
        }
        _stack.push(a / b);
    }
}

int RPN::calculate(const std::string& expression) {
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (isOperator(token)) {
            performOperation(token);
        } else {
            if (token.length() != 1 || !isdigit(token[0])) {
                throw RPNException();
            }
            _stack.push(atoi(token.c_str()));
        }
    }

    if (_stack.size() != 1) {
        throw RPNException();
    }

    return _stack.top();
}