#include "ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <limits>
#include <cctype>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

static std::string toLower(const std::string& s) {
    std::string res = s;
    for (size_t i = 0; i < res.size(); ++i)
        res[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(res[i])));
    return res;
}

static bool isSpecialFloat(const std::string& s) {
    std::string l = toLower(s);
    return l == "nanf" || l == "+inff" || l == "-inff" || l == "inff";
}
static bool isSpecialDouble(const std::string& s) {
    std::string l = toLower(s);
    return l == "nan" || l == "+inf" || l == "-inf" || l == "inf";
}

static bool isChar(const std::string& s) {
    return s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0]));
}

static bool parseLongLong(const std::string& s, long long& out) {
    if (s.empty()) return false;

    size_t i = 0;
    bool neg = false;
    if (s[0] == '-' || s[0] == '+') {
        neg = (s[0] == '-');
        i++;
        if (i == s.size()) return false;
    }
    long long val = 0;
    for (; i < s.size(); i++) {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
        int digit = s[i] - '0';
        if (val > (std::numeric_limits<long long>::max() - digit) / 10)
            return false;
        val = val * 10 + digit;
    }
    out = neg ? -val : val;
    return true;
}

static bool parseInt(const std::string& s, int& out) {
    long long val;
    if (!parseLongLong(s, val))
        return false;
    if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
        return false;
    out = static_cast<int>(val);
    return true;
}

static bool parseDouble(const std::string& s, double& out) {
    if (s.empty()) return false;

    size_t i = 0;
    bool neg = false;
    if (s[0] == '+' || s[0] == '-') {
        neg = (s[0] == '-');
        i++;
        if (i == s.size()) return false;
    }
    double result = 0.0;
    bool dotSeen = false;
    double fracFactor = 0.1;
    bool expNeg = false;
    int exponent = 0;
    bool expPart = false;
    bool digitsBeforeExp = false;

    std::string basePart = s.substr(i);
    size_t pos = 0;

    while (pos < basePart.size()) {
        char c = basePart[pos];
        if (c == '.') {
            if (dotSeen || expPart) return false;
            dotSeen = true;
            pos++;
        } else if (c == 'e' || c == 'E') {
            if (expPart) return false;
            expPart = true;
            pos++;
            if (pos == basePart.size()) return false;
            if (basePart[pos] == '+' || basePart[pos] == '-') {
                expNeg = (basePart[pos] == '-');
                pos++;
            }
            if (pos == basePart.size()) return false;
            break;
        } else if (std::isdigit(static_cast<unsigned char>(c))) {
            digitsBeforeExp = true;
            if (!dotSeen)
                result = result * 10.0 + (c - '0');
            else {
                result += (c - '0') * fracFactor;
                fracFactor *= 0.1;
            }
            pos++;
        } else return false;
    }

    if (!digitsBeforeExp) return false;

    if (expPart) {
        int expVal = 0;
        bool expDigits = false;
        for (; pos < basePart.size(); pos++) {
            char c = basePart[pos];
            if (!std::isdigit(static_cast<unsigned char>(c))) return false;
            expDigits = true;
            int digit = c - '0';
            if (expVal > (std::numeric_limits<int>::max() - digit) / 10)
                return false;
            expVal = expVal * 10 + digit;
        }
        if (!expDigits) return false;
        exponent = expNeg ? -expVal : expVal;
    }

    if (exponent > 309) {
        out = neg ? -std::numeric_limits<double>::infinity() : std::numeric_limits<double>::infinity();
        return true;
    }
    if (exponent < -324) {
        out = neg ? -0.0 : 0.0;
        return true;
    }

    double pow10 = 1.0;
    int absExp = exponent > 0 ? exponent : -exponent;
    for (int j = 0; j < absExp; j++) {
        pow10 *= 10.0;
    }

    if (exponent < 0)
        result /= pow10;
    else
        result *= pow10;

    if (result == 0.0) {
        out = neg ? -0.0 : 0.0;
        return true;
    }

    if (result > std::numeric_limits<double>::max()) {
        out = neg ? -std::numeric_limits<double>::infinity() : std::numeric_limits<double>::infinity();
        return true;
    }

    out = neg ? -result : result;
    return true;
}


static bool parseFloat(const std::string& s, float& out) {
    if (s.empty() || s[s.size()-1] != 'f') return false;

    std::string sub = s.substr(0, s.size()-1);
    double d;
    if (!parseDouble(sub, d)) return false;

    if (std::abs(d) < std::numeric_limits<float>::min() && d != 0.0) {
        out = 0.0f;
        return true;
    }

    if (std::isinf(d)) {
        out = static_cast<float>(d);
        return true;
    }

    if (d > std::numeric_limits<float>::max()) {
        out = std::numeric_limits<float>::infinity();
        return true;
    }

    if (d < -std::numeric_limits<float>::max()) {
        out = -std::numeric_limits<float>::infinity();
        return true;
    }

    out = static_cast<float>(d);
    return true;
}

static void printChar(char c, bool impossible, bool nonDisp) {
    std::cout << "char: ";
    if (impossible && !nonDisp) std::cout << "impossible\n";
    else if (nonDisp) std::cout << "Non displayable\n";
    else std::cout << "'" << c << "'\n";
}
static void printInt(int i, bool impossible) {
    std::cout << "int: ";
    if (impossible) std::cout << "impossible\n";
    else std::cout << i << "\n";
}
static void printFloat(float f, bool impossible, const std::string& literal) {
    std::cout << "float: ";
    if (impossible) {
        std::string l = toLower(literal);
        if (l == "nanf") std::cout << "nanf\n";
        else if (l == "+inff" || l == "inff") std::cout << "+inff\n";
        else if (l == "-inff") std::cout << "-inff\n";
        else std::cout << "impossible\n";
    }
    else {
        if (std::signbit(f) && f == 0.0f)
            std::cout << "-0.0f\n";
        else {
            std::cout << f;
            if (f == static_cast<int>(f)) std::cout << ".0";
            std::cout << "f\n";
        }
    }
}
static void printDouble(double d, bool impossible, const std::string& literal) {
    std::cout << "double: ";
    if (impossible) {
        std::string l = toLower(literal);
        if (l == "nanf" || l == "nan") std::cout << "nan\n";
        else if (l == "+inff" || l == "+inf" || l == "inff" || l == "inf") std::cout << "+inf\n";
        else if (l == "-inff" || l == "-inf") std::cout << "-inf\n";
        else std::cout << "impossible\n";
    }
    else {
        std::cout << d;
        if (d == static_cast<int>(d)) std::cout << ".0";
        std::cout << "\n";
    }
}

void ScalarConverter::convert(const std::string& literal) {
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;
    bool charImp = false;
    bool intImp = false;
    bool floatImp = false;
    bool doubleImp = false;
    bool nonDisp = false;

    std::string l = toLower(literal);

    if (isChar(literal)) {
        c = literal[0];
        unsigned char uc = static_cast<unsigned char>(c);
        i = static_cast<int>(uc);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        charImp = (i > 127);
        nonDisp = (!std::isprint(uc) && uc <= 127);
    }
    else if (parseInt(literal, i)) {
        c = static_cast<char>(i);
        charImp = (i < 0 || i > 127);
        unsigned char uc = static_cast<unsigned char>(c);
        nonDisp = (!std::isprint(uc) && uc <= 127);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    else if (isSpecialFloat(literal)) {
        floatImp = false;
        doubleImp = false;
        intImp = true;
        charImp = true;

        if (l == "nanf") f = std::numeric_limits<float>::quiet_NaN();
        else if (l == "+inff" || l == "inff") f = std::numeric_limits<float>::infinity();
        else f = -std::numeric_limits<float>::infinity();
        d = static_cast<double>(f);
    }
    else if (isSpecialDouble(literal)) {
        doubleImp = false;
        floatImp = false;
        intImp = true;
        charImp = true;

        if (l == "nan") d = std::numeric_limits<double>::quiet_NaN();
        else if (l == "+inf" || l == "inf") d = std::numeric_limits<double>::infinity();
        else d = -std::numeric_limits<double>::infinity();
        f = static_cast<float>(d);
    }
    else if (literal.size() > 1 && literal[literal.size() - 1] == 'f' && parseFloat(literal, f)) {
        d = static_cast<double>(f);

        if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max()) intImp = true;
        else i = static_cast<int>(f);

        if (f < 0 || f > 127 || !std::isprint(static_cast<unsigned char>(static_cast<char>(f)))) charImp = true;
        else c = static_cast<char>(f);
    }
    else if (parseDouble(literal, d)) {
        f = static_cast<float>(d);
        if (f == 0.0f && d != 0.0)
            floatImp = true;

        if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) intImp = true;
        else i = static_cast<int>(d);

        if (d < 0 || d > 127 || !std::isprint(static_cast<unsigned char>(static_cast<char>(d)))) charImp = true;
        else c = static_cast<char>(d);
    }
    else {
        std::cout << "Error: Invalid input\n";
        return;
    }

    printChar(c, charImp, nonDisp);
    printInt(i, intImp);
    printFloat(f, floatImp, literal);
    printDouble(d, doubleImp, literal);
}
