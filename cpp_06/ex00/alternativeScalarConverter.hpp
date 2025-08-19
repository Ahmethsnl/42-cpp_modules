#ifndef ALTERNATIVESCALARCONVERTER_HPP
#define ALTERNATIVESCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    ~ScalarConverter();

    static void printChar(double d);
    static void printInt(double d);
    static void printFloat(double d);
    static void printDouble(double d);

public:
    static void convert(const std::string& literal);
};

#endif
