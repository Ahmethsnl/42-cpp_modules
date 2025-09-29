#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib> // rand()
#include <ctime>   // time()

int main() {
    std::cout << "=== SPAN TESTS ===" << std::endl;
    
    // Subject test case
    std::cout << "\n--- Subject Test Case ---" << std::endl;
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << sp.shortestSpan() << std::endl;  // Should be 2
        std::cout << sp.longestSpan() << std::endl;   // Should be 14
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    // Range addition test
    std::cout << "\n--- Range Addition Test ---" << std::endl;
    try {
        Span sp(10);
        sp.addNumber(1);
        sp.addNumber(5);
        
        // Create a vector to add via range
        std::vector<int> numbers;
        numbers.push_back(10);
        numbers.push_back(15);
        numbers.push_back(20);
        
        sp.addRange(numbers.begin(), numbers.end());
        
        std::cout << "After range addition:" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    // Large span test (10,000+ numbers)
    std::cout << "\n--- Large Span Test (15,000 numbers) ---" << std::endl;
    try {
        srand(time(NULL));
        Span bigSpan(15000);
        
        // Add numbers using range from array
        std::vector<int> largeNumbers;
        for (int i = 0; i < 15000; ++i) {
            largeNumbers.push_back(rand() % 100000);  // Random numbers 0-99999
        }
        
        bigSpan.addRange(largeNumbers.begin(), largeNumbers.end());
        
        std::cout << "Large span shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Large span longest: " << bigSpan.longestSpan() << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    // Exception tests
    std::cout << "\n--- Exception Tests ---" << std::endl;
    try {
        Span sp(2);
        sp.addNumber(1);
        std::cout << "Trying shortestSpan with only 1 number:" << std::endl;
        sp.shortestSpan();  // Should throw
    } catch (const std::exception& e) {
        std::cerr << "Expected exception: " << e.what() << std::endl;
    }
    
    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);  // Should throw - span full
    } catch (const std::exception& e) {
        std::cerr << "Expected exception: " << e.what() << std::endl;
    }

    return 0;
}
