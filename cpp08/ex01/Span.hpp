#pragma once
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>

class SpanFullException : public std::exception {
public:
    virtual const char* what() const throw() { return "Span is already full"; }
};

class SpanNotEnoughNumbersException : public std::exception {
public:
    virtual const char* what() const throw() { return "Not enough numbers stored to find a span"; }
};

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);

    template <typename InputIt>
    void addNumbers(InputIt begin, InputIt end) {
        if (static_cast<unsigned int>(std::distance(begin, end)) + _numbers.size() > _maxSize)
            throw SpanFullException();
        _numbers.insert(_numbers.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;
};