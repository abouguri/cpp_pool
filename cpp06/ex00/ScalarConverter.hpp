#pragma once

#include <string>

class ScalarConverter {
public:
    static void convert(const std::string& literal);

private:
    static bool isChar(const std::string& literal);
    static bool isInt(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);
    static bool isPseudoLiteral(const std::string& literal);

    static void printChar(double value, bool impossible = false);
    static void printInt(double value, bool impossible = false);
    static void printFloat(double value, bool impossible = false, bool nan_inf = false, const std::string& original = "");
    static void printDouble(double value, bool impossible = false, bool nan_inf = false, const std::string& original = "");
};