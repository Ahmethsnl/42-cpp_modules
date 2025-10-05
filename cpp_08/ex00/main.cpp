#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
    std::cout << "=== TESTING EASYFIND ===" << std::endl;
    
    std::cout << "\n--- std::vector test ---" << std::endl;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    try {
        std::vector<int>::const_iterator it = easyfind(vec, 3);
        std::cout << "Found value 3 in vector" << std::endl;
        std::cout << "Value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    try {
        easyfind(vec, 10);
        std::cout << "Found 10 (this shouldn't print)" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Expected error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- std::list test ---" << std::endl;
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    
    try {
        std::list<int>::const_iterator it = easyfind(lst, 20);
        std::cout << "Found value 20 in list" << std::endl;
        std::cout << "Value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- std::deque test ---" << std::endl;
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    
    try {
        std::deque<int>::const_iterator it = easyfind(deq, 200);
        std::cout << "Found value 200 in deque" << std::endl;
        std::cout << "Value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
