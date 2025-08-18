#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data sample("TestObject", 7, 1.23f);

    std::cout << "Address of sample: " << &sample << std::endl;

    uintptr_t encoded = Serializer::toInteger(&sample);
    std::cout << "Serialized (uintptr_t): " << encoded << std::endl;

    Data* recovered = Serializer::toPointer(encoded);
    std::cout << "Recovered address: " << recovered << std::endl;

    if (recovered == &sample)
        std::cout << "OK -> Same pointer!" << std::endl;

    std::cout << "Recovered content: "
              << recovered->label << ", "
              << recovered->number << ", "
              << recovered->ratio << std::endl;

    return 0;
}
