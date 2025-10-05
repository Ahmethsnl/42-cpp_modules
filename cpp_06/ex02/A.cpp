#include "A.hpp"

A::A() {}

A::A(const A& other) : Base(other) {}

A& A::operator=(const A& other) {
    if (this != &other)
        Base::operator=(other);
    return *this;
}

A::~A() {}
