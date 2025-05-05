#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    // Constructors
    Fixed(void);                        // Default constructor
    Fixed(const int value);             // Int constructor
    Fixed(const float value);           // Float constructor
    Fixed(const Fixed &src);            // Copy constructor
    
    // Destructor
    ~Fixed(void);
    
    // Assignment operator
    Fixed& operator=(const Fixed &rhs);
    
    // Comparison operators
    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;
    
    // Arithmetic operators
    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;
    
    // Increment/Decrement operators
    Fixed& operator++();    // Pre-increment
    Fixed operator++(int);  // Post-increment
    Fixed& operator--();    // Pre-decrement
    Fixed operator--(int);  // Post-decrement
    
    // Static min/max functions
    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);
    
    // Conversion functions
    float toFloat(void) const;
    int toInt(void) const;
    
    // Member functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

// Stream insertion operator overload
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif