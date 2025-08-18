#include "Serializer.hpp"

// canonical form - hidden
Serializer::Serializer() {}
Serializer::Serializer(const Serializer&) {}
Serializer& Serializer::operator=(const Serializer&) { return *this; }
Serializer::~Serializer() {}

uintptr_t Serializer::toInteger(Data* pointer) {
    return reinterpret_cast<uintptr_t>(pointer);
}

Data* Serializer::toPointer(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
