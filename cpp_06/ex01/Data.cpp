#include "Data.hpp"

Data::Data() : label(""), number(0), ratio(0.0f) {}

Data::Data(const std::string& lbl, int num, float r)
: label(lbl), number(num), ratio(r) {}

Data& Data::operator=(const Data& other)
{
    if (this != &other)
    {
        label = other.label;
        number = other.number;
        ratio = other.ratio;
    }
    return *this;
}

Data::~Data() {}