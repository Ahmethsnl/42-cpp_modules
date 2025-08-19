#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> // std::out_of_range
#include <cstddef>   // size_t

template <typename T>
class Array {
private:
    T* _data;
    unsigned int _size;

public:
    // Default ctor
    Array() : _data(NULL), _size(0) {}

    // Size ctor
    Array(unsigned int n) : _data(NULL), _size(n) {
        if (n > 0)
            _data = new T[n](); // () -> default-init
    }

    // Copy ctor
    Array(const Array& other) : _data(NULL), _size(other._size) {
        if (_size > 0) {
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        }
    }

    // Assignment
    Array& operator=(const Array& other) {
        if (this != &other) {
            // önce eskiyi temizle
            delete[] _data;
            _data = NULL;
            _size = other._size;
            if (_size > 0) {
                _data = new T[_size];
                for (unsigned int i = 0; i < _size; ++i)
                    _data[i] = other._data[i];
            }
        }
        return *this;
    }

    // Destructor
    ~Array() {
        delete[] _data;
    }

    // [] operator
    T& operator[](unsigned int idx) {
        if (idx >= _size)
            throw std::out_of_range("Index out of range");
        return _data[idx];
    }

    const T& operator[](unsigned int idx) const {
        if (idx >= _size)
            throw std::out_of_range("Index out of range");
        return _data[idx];
    }

    // size() const
    unsigned int size() const {
        return _size;
    }
};

#endif
