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

// Comparison operators
bool Fixed::operator>(const Fixed &rhs) const {
    return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const {
    return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed &rhs) const {
    return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const {
    return this->getRawBits() != rhs.getRawBits();
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(this->getRawBits() + rhs.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(this->getRawBits() - rhs.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    Fixed result;
    // When multiplying fixed point numbers, we need to shift back to maintain the correct fixed-point representation
    result.setRawBits((this->getRawBits() * rhs.getRawBits()) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    // Check for division by zero
    if (rhs.getRawBits() == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        exit(1);
    }
    
    Fixed result;
    // When dividing fixed point numbers, we need to shift left to maintain the correct fixed-point representation
    result.setRawBits((this->getRawBits() << _fractionalBits) / rhs.getRawBits());
    return result;
}

// Increment/Decrement operators
Fixed& Fixed::operator++() {
    // Pre-increment (++a)
    _fixedPointValue += 1;  // Increment by the smallest representable value (2^-8)
    return *this;
}

Fixed Fixed::operator++(int) {
    // Post-increment (a++)
    Fixed old = *this;  // Save current value
    ++(*this);          // Increment
    return old;         // Return saved value
}

Fixed& Fixed::operator--() {
    // Pre-decrement (--a)
    _fixedPointValue -= 1;  // Decrement by the smallest representable value (2^-8)
    return *this;
}

Fixed Fixed::operator--(int) {
    // Post-decrement (a--)
    Fixed old = *this;  // Save current value
    --(*this);          // Decrement
    return old;         // Return saved value
}

// Static min/max functions
Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
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