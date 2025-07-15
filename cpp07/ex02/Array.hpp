#pragma once
#include <cstddef> // for size_t
#include <stdexcept> // for std::exception

template <typename T>
class Array {
private:
    T* _data;
    unsigned int _size;

public:
    // Default constructor: empty array
    Array() : _data(NULL), _size(0) {}

    // Constructor with size
    Array(unsigned int n) : _data(NULL), _size(n) {
        if (n > 0)
            _data = new T[n]();
        else
            _data = NULL;
    }

    // Copy constructor
    Array(const Array& other) : _data(NULL), _size(other._size) {
        if (_size > 0) {
            _data = new T[_size]();
            for (unsigned int i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        }
    }

    // Assignment operator
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            if (_size > 0) {
                _data = new T[_size]();
                for (unsigned int i = 0; i < _size; ++i)
                    _data[i] = other._data[i];
            } else {
                _data = NULL;
            }
        }
        return *this;
    }

    // Destructor
    ~Array() {
        delete[] _data;
    }

    // Subscript operator
    T& operator[](unsigned int index) {
        if (index >= _size)
            throw std::exception();
        return _data[index];
    }
    const T& operator[](unsigned int index) const {
        if (index >= _size)
            throw std::exception();
        return _data[index];
    }

    // size() member function
    unsigned int size() const {
        return _size;
    }
};