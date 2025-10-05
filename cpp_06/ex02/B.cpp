#include "B.hpp"

B::B() {}

B::B(const B& other) : Base(other) {}

B& B::operator=(const B& other) {
    if (this != &other)
        Base::operator=(other);
    return *this;
}

B::~B() {}
