#include <iostream>
#include "Array.hpp"

int main() {
    // boş array
    Array<int> a;
    std::cout << "a.size() = " << a.size() << std::endl;

    // 5 elemanlı array (default init -> 0)
    Array<int> b(5);
    std::cout << "b.size() = " << b.size() << std::endl;
    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << "b[" << i << "] = " << b[i] << std::endl;

    // değer atama
    for (unsigned int i = 0; i < b.size(); ++i)
        b[i] = i * 10;

    std::cout << "After modification:" << std::endl;
    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << "b[" << i << "] = " << b[i] << std::endl;

    // copy constructor
    Array<int> c(b);
    std::cout << "c (copy of b):" << std::endl;
    for (unsigned int i = 0; i < c.size(); ++i)
        std::cout << "c[" << i << "] = " << c[i] << std::endl;

    // orijinali değiştir, kopya etkilenmesin
    b[0] = 999;
    std::cout << "After b[0]=999, c[0] = " << c[0] << std::endl;

    // assignment operator
    Array<int> d;
    d = b;
    std::cout << "d (assigned from b):" << std::endl;
    for (unsigned int i = 0; i < d.size(); ++i)
        std::cout << "d[" << i << "] = " << d[i] << std::endl;

    // out of range test
    try {
        std::cout << b[42] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // başka tip test: std::string
    Array<std::string> s(3);
    s[0] = "hello";
    s[1] = "world";
    s[2] = "!";
    for (unsigned int i = 0; i < s.size(); ++i)
        std::cout << "s[" << i << "] = " << s[i] << std::endl;

    return 0;
}
