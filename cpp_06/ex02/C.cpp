#include "C.hpp"

C::C() {}

C::C(const C& other) : Base(other) {}

C& C::operator=(const C& other) {
    if (this != &other)
        Base::operator=(other);
    return *this;
}

C::~C() {}
