#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <limits>
#include <cerrno>

static bool isDisplayableChar(int c) {
    return c >= 32 && c <= 126;
}

bool ScalarConverter::isChar(const std::string& literal) {
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool ScalarConverter::isInt(const std::string& literal) {
    if (literal.empty()) return false;
    size_t i = 0;
    if (literal[0] == '+' || literal[0] == '-') i++;
    if (i == literal.size()) return false;
    for (; i < literal.size(); ++i) {
        if (!isdigit(literal[i])) return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return true;
    size_t len = literal.length();
    if (len < 2 || literal[len - 1] != 'f') return false;
    size_t dot = literal.find('.');
     if (dot == std::string::npos) return false;
    size_t i = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
    bool foundDigit = false;
    for (; i < dot; ++i) {
        if (!isdigit(literal[i])) return false;
        foundDigit = true;
    }
    if (!foundDigit) return false;
    foundDigit = false;
    for (i = dot + 1; i < len - 1; ++i) {
        if (!isdigit(literal[i])) return false;
        foundDigit = true;
    }
    return foundDigit;
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return true;
    size_t dot = literal.find('.');
    if (dot == std::string::npos) return false;
    size_t i = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
    bool foundDigit = false;
    for (; i < dot; ++i) {
        if (!isdigit(literal[i])) return false;
        foundDigit = true;
    }
    if (!foundDigit) return false;
    foundDigit = false;
    for (i = dot + 1; i < literal.size(); ++i) {
        if (!isdigit(literal[i])) return false;
        foundDigit = true;
    }
    return foundDigit;
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
    return literal == "-inff" || literal == "+inff" || literal == "nanf"
        || literal == "-inf" || literal == "+inf" || literal == "nan";
}

void ScalarConverter::printChar(double value, bool impossible) {
    std::cout << "char: ";
    if (impossible || value < 0 || value > 255 || !isDisplayableChar(static_cast<int>(value)))
        std::cout << (impossible ? "impossible" : "Non displayable") << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value, bool impossible) {
    std::cout << "int: ";
    if (impossible || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value, bool impossible, bool nan_inf, const std::string& original) {
    std::cout << "float: ";
    if (impossible)
        std::cout << "impossible" << std::endl;
    else if (nan_inf)
        std::cout << original << std::endl;
    else {
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value, bool impossible, bool nan_inf, const std::string& original) {
    std::cout << "double: ";
    if (impossible)
        std::cout << "impossible" << std::endl;
    else if (nan_inf)
        std::cout << original << std::endl;
    else {
        std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal) {
    if (isChar(literal)) {
        char c = literal[1];
        double value = static_cast<double>(c);
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
        return;
    }
    if (isPseudoLiteral(literal)) {
        bool isFloatPseudo = (literal == "-inff" || literal == "+inff" || literal == "nanf");
        bool isDoublePseudo = (literal == "-inf" || literal == "+inf" || literal == "nan");
        printChar(0, true);
        printInt(0, true);
        printFloat(0, false, true, isFloatPseudo ? literal : (literal + "f"));
        printDouble(0, false, true, isDoublePseudo ? literal : literal.substr(0, literal.length() - 1));
        return;
    }
    char* endptr = NULL;
    errno = 0;
    double value = std::strtod(literal.c_str(), &endptr);
    bool conversionError = (errno != 0 || endptr == literal.c_str() || *endptr != '\0');
    if (isInt(literal) && !conversionError) {
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
        return;
    }
    if (isFloat(literal) && !conversionError) {
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
        return;
    }
    if (isDouble(literal) && !conversionError) {
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
        return;
    }
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}