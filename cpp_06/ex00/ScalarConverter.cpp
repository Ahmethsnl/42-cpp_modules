#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::printChar(double d) {
    std::cout << "char: ";
    if (std::isnan(d) || d < 0 || d > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<char>(d)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(d) << "'\n";
}

void ScalarConverter::printInt(double d) {
    std::cout << "int: ";
    if (std::isnan(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(d) << "\n";
}

void ScalarConverter::printFloat(double d) {
    std::cout << "float: ";
    if (std::isnan(d))
        std::cout << "nanf\n";
    else if (std::isinf(d))
        std::cout << (d > 0 ? "+inff\n" : "-inff\n");
    else {
        float f = static_cast<float>(d);
        if (f == 0.0f && std::signbit(d)) std::cout << "-0.0f\n";
        else {
            std::cout << f;
            if (f == static_cast<int>(f)) std::cout << ".0";
            std::cout << "f\n";
        }
    }
}

void ScalarConverter::printDouble(double d) {
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan\n";
    else if (std::isinf(d))
        std::cout << (d > 0 ? "+inf\n" : "-inf\n");
    else {
        std::cout << d;
        if (d == static_cast<int>(d)) std::cout << ".0";
        std::cout << "\n";
    }
}

void ScalarConverter::convert(const std::string& literal) {
    double d = 0.0;
    bool isCharLiteral = literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0]));

    if (isCharLiteral) {
        d = static_cast<double>(literal[0]);
    } else {
        if (literal == "nan" || literal == "nanf" || literal == "NAN" || literal == "NANF") {
            d = std::numeric_limits<double>::quiet_NaN();
        } else if (literal == "+inf" || literal == "+inff" || literal == "+INFF" || literal == "+INF") {
            d = std::numeric_limits<double>::infinity();
        } else if (literal == "-inf" || literal == "-inff" || literal == "-INFF" || literal == "-INF") {
            d = -std::numeric_limits<double>::infinity();
        } else {
            const char* cstr = literal.c_str();
            char* endptr = NULL;
            if (literal[literal.length() - 1] == 'f' && literal != "f") {
                d = std::strtod(literal.substr(0, literal.length() - 1).c_str(), &endptr);
            } else {
                d = std::strtod(cstr, &endptr);
            }
            if (*endptr != '\0') {
                std::cout << "Error: Invalid input\n";
                return;
            }
        }
    }

    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}
