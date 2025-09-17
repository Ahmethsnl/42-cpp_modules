#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    try {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        std::cout << "Found: " << *easyfind(vec, 3) << std::endl;
        std::cout << "Found: " << *easyfind(vec, 6) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::list<int> lst = {10, 20, 30, 40};
        std::cout << "Found: " << *easyfind(lst, 20) << std::endl;
        std::cout << "Found: " << *easyfind(lst, 50) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
