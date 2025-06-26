#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <limits>

static bool isChar(const std::string& literal) {
    return literal.length() == 1 && 
          !(literal[0] >= '0' && literal[0] <= '9') &&
          (literal[0] >= 32 && literal[0] <= 126);
}

static bool isInt(const std::string& literal) {
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+') i = 1;
    if (i == literal.size()) return false;
    for (; i < literal.size(); ++i) {
        if (!(literal[i] >= '0' && literal[i] <= '9'))
            return false;
    }
    return true;
}

static bool isFloat(const std::string& literal) {
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return true;

    bool hasDigit = false;
    bool hasDecimal = false;
    bool hasExponent = false;
    bool hasF = false;
    size_t i = 0;

    if (literal[0] == '-' || literal[0] == '+') i = 1;
    
    for (; i < literal.size(); ++i) {
        if (literal[i] >= '0' && literal[i] <= '9') {
            hasDigit = true;
            continue;
        }
        if (literal[i] == '.' && !hasDecimal && !hasExponent) {
            hasDecimal = true;
            continue;
        }
        if ((literal[i] == 'e' || literal[i] == 'E') && !hasExponent && hasDigit) {
            hasExponent = true;
            if (i+1 < literal.size() && (literal[i+1] == '+' || literal[i+1] == '-')) {
                i++;
            }
            if (i+1 >= literal.size()) return false;
            continue;
        }
        if (literal[i] == 'f' && i == literal.size()-1 && hasDigit) {
            hasF = true;
            continue;
        }
        return false;
    }
    return hasF && hasDigit;
}

static bool isDouble(const std::string& literal) {
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return true;

    bool hasDigit = false;
    bool hasDecimal = false;
    bool hasExponent = false;
    size_t i = 0;

    if (literal[0] == '-' || literal[0] == '+') i = 1;
    
    for (; i < literal.size(); ++i) {
        if (literal[i] >= '0' && literal[i] <= '9') {
            hasDigit = true;
            continue;
        }
        if (literal[i] == '.' && !hasDecimal && !hasExponent) {
            hasDecimal = true;
            continue;
        }
        if ((literal[i] == 'e' || literal[i] == 'E') && !hasExponent && hasDigit) {
            hasExponent = true;
            if (i+1 < literal.size() && (literal[i+1] == '+' || literal[i+1] == '-')) {
                i++;
            }
            if (i+1 >= literal.size()) return false;
            continue;
        }
        return false;
    }
    return hasDigit;
}

static double stringToDouble(const std::string& literal) {
    if (literal == "-inf" || literal == "-inff") return -std::numeric_limits<double>::infinity();
    if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff") return std::numeric_limits<double>::infinity();
    if (literal == "nan" || literal == "nanf") return std::numeric_limits<double>::quiet_NaN();

    double result = 0.0;
    double fraction = 1.0;
    int exponent = 0;
    int exponent_sign = 1;
    bool negative = false;
    bool in_fraction = false;
    bool in_exponent = false;
    size_t i = 0;

    if (literal[0] == '-') { negative = true; i = 1; }
    else if (literal[0] == '+') { i = 1; }

    for (; i < literal.size(); ++i) {
        char c = literal[i];
        if (c == 'f' && i == literal.size()-1) break;
        
        if (c == '.') {
            in_fraction = true;
            continue;
        }
        if ((c == 'e' || c == 'E') && !in_exponent) {
            in_exponent = true;
            if (i+1 < literal.size() && literal[i+1] == '-') {
                exponent_sign = -1;
                i++;
            }
            else if (i+1 < literal.size() && literal[i+1] == '+') {
                i++;
            }
            continue;
        }
        if (c >= '0' && c <= '9') {
            if (in_exponent) {
                exponent = exponent * 10 + (c - '0');
            }
            else if (in_fraction) {
                fraction *= 0.1;
                result += (c - '0') * fraction;
            }
            else {
                result = result * 10.0 + (c - '0');
            }
            continue;
        }
        return std::numeric_limits<double>::quiet_NaN();
    }

    if (negative) result = -result;
    if (exponent != 0) result *= std::pow(10.0, exponent * exponent_sign);
    
    return result;
}

static void printResults(double d) {
    // char
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max()) {
        std::cout << "impossible" << std::endl;
    }
    else if (!std::isprint(static_cast<char>(d))) {
        std::cout << "Non displayable" << std::endl;
    }
    else {
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    }

    // int
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
    }
    else {
        std::cout << static_cast<int>(d) << std::endl;
    }

    // float
    std::cout << "float: ";
    if (std::isinf(d)) {
        std::cout << (d < 0 ? "-inff" : "+inff") << std::endl;
    }
    else if (std::isnan(d)) {
        std::cout << "nanf" << std::endl;
    }
    else {
        float f = static_cast<float>(d);
        if (f == std::floor(f) && f <= 1e6 && f >= -1e6) {
            std::cout << f << ".0f" << std::endl;
        }
        else {
            std::cout << f << "f" << std::endl;
        }
    }

    // double
    std::cout << "double: ";
    if (std::isinf(d)) {
        std::cout << (d < 0 ? "-inf" : "+inf") << std::endl;
    }
    else if (std::isnan(d)) {
        std::cout << "nan" << std::endl;
    }
    else if (d == std::floor(d) && d <= 1e6 && d >= -1e6) {
        std::cout << d << ".0" << std::endl;
    }
    else {
        std::cout << d << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
        std::cout << "Error: Empty input" << std::endl;
        return;
    }

    double d = 0.0;

    if (isChar(literal)) {
        d = static_cast<double>(literal[0]);
    }
    else if (isInt(literal)) {
        long tmp = 0;
        int sign = 1;
        size_t i = 0;
        
        if (literal[0] == '-') { sign = -1; i = 1; }
        else if (literal[0] == '+') { i = 1; }
        
        for (; i < literal.size(); ++i) {
            tmp = tmp * 10 + (literal[i] - '0');
        }
        d = static_cast<double>(tmp * sign);
    }
    else if (isFloat(literal) || isDouble(literal)) {
        d = stringToDouble(literal);
    }
    else {
        std::cout << "Error: Invalid input" << std::endl;
        return;
    }

    printResults(d);
}