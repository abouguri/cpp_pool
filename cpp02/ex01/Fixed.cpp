#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Default constructor
Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Int constructor
Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = value << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

// Destructor
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

// Convert to float
float Fixed::toFloat(void) const {
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

// Convert to int
int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

// Get raw bits
int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

// Set raw bits
void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

// Stream insertion operator overload
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}