#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
    std::string label;
    int number;
    float ratio;

    Data();
    Data(const std::string& lbl, int num, float r);
    Data& operator=(const Data&);
    ~Data();
};

#endif
