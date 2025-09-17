#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        std::vector<int> extraNumbers = {1, 2, 3};
        sp.addRange(extraNumbers.begin(), extraNumbers.end());
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Span sp = Span(10000);
        for (int i = 0; i < 10000; ++i) {
            sp.addNumber(i);
        }
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
