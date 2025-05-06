#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed& Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

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
    result.setRawBits((this->getRawBits() * rhs.getRawBits()) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    if (rhs.getRawBits() == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        exit(1);
    }
    
    Fixed result;
    result.setRawBits((this->getRawBits() << _fractionalBits) / rhs.getRawBits());
    return result;
}

Fixed& Fixed::operator++() {
    _fixedPointValue += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed old = *this;
    ++(*this);
    return old;
}

Fixed& Fixed::operator--() {
    _fixedPointValue -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed old = *this;
    --(*this);
    return old;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    if (a < b) 
        return a;
    else
        return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b) 
        return a;
    else
        return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    if (a > b) 
        return a;
    else
        return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b) 
        return a;
    else
        return b;
}

float Fixed::toFloat(void) const {
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}