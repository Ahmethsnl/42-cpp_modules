#include <iostream>
#include <string>
#include "iter.hpp"

// Non-const function: modifies elements
void doubleInt(int& x) {
    x *= 2;
}

// Const function: only reads elements  
void printInt(const int& x) {
    std::cout << x << " ";
}

template <typename T>
void printElement(const T& elem) {
    std::cout << elem << " ";
}

template <typename T>
void modifyElement(T& elem) {
    (void)elem; // Unused parameter warning'ini önle
}

int main() {
    std::cout << "=== NON-CONST ARRAY TESTS ===" << std::endl;
    
    // Non-const array
    int intArray[5] = {1, 2, 3, 4, 5};
    std::cout << "Original array: ";
    iter(intArray, 5, printInt);
    std::cout << std::endl;
    
    // Modify elements (non-const function)
    iter(intArray, 5, doubleInt);
    std::cout << "After doubling: ";
    iter(intArray, 5, printInt);
    std::cout << std::endl;
    
    std::cout << "\n=== CONST ARRAY TESTS ===" << std::endl;
    
    // Const array
    const int constArray[3] = {10, 20, 30};
    std::cout << "Const array: ";
    iter(constArray, 3, printInt);  // Works with const array
    std::cout << std::endl;
    
    std::cout << "\n=== STRING ARRAY TEST ===" << std::endl;
    std::string strArray[3] = {"hello", "world", "templates"};
    std::cout << "String array: ";
    iter(strArray, 3, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
