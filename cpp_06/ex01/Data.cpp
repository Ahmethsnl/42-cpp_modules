#include "Data.hpp"

Data::Data() : label(""), number(0), ratio(0.0f) {}

Data::Data(const std::string& lbl, int num, float r)
: label(lbl), number(num), ratio(r) {}
