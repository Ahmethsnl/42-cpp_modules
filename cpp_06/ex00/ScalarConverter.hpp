#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
public:
    ScalarConverter();

    ScalarConverter(const ScalarConverter&);

    ScalarConverter& operator=(const ScalarConverter&);

    ~ScalarConverter();

    static void convert(const std::string& literal);

private:
    static void printChar(double d);
    static void printInt(double d);
    static void printFloat(double d);
    static void printDouble(double d);
};

#endif