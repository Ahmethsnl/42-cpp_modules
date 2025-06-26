#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {*this = src;}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	if (this == &src)
		return *this;
	return *this;
}

bool isChar(const std::string &str)
{
    if (str.length() == 1 && !std::isdigit(str[0]))
        return true;
    return false;
}

bool convertChar(int &_int, char &_char, float &_float, double &_double, const std::string &str, bool &impossible, bool &displayable)
{
    _char = str[0];
    if (isChar(str))
    {
        if (!std::isprint(_char))
            displayable = false;
        if (isChar(str) && !displayable)
        {
            impossible = false;
        }
        else
        {
            _char = 0;
            return impossible;
        }
        _char = str[0];
        _int = static_cast<int>(_char);
        _float = static_cast<float>(_char);
        _double = static_cast<double>(_char);
    }
    return false;
}

bool isInt(const std::string &str)
{
    if (str.empty())
        return false;
    else if (str.length() == 1 && !std::isdigit(str[0]))
        return false;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool convertInt(int &_int, char &_char, float &_float, double &_double,
    const std::string &str, bool &impossible)
{
    long long res = 0;
    bool isNegative = false;
    size_t i = 0;

    if (str[i] == '-')
    {
        isNegative = true;
        i = 1;
    }
    else if (str[i] == '+')
        i = 1;

    for (; i < str.length(); ++i)
    {
        if (std::isdigit(str[i]))
            res = res * 10 + (str[i] - '0');
        else
            break;
    }
    if (isNegative)
        res = -res;

    if (res < std::numeric_limits<int>::min() || res > std::numeric_limits<int>::max())
    {
        impossible = true;
        return impossible;
    }
    
    _int = static_cast<int>(res);
    _char = static_cast<char>(_int);
    _float = static_cast<float>(_int);
    _double = static_cast<double>(_int);
    
    return false;
}

bool isFloat(const std::string& str) 
{
    if (str.empty())
        return false;

    if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf" ||
        str == "-inf" || str == "+inf" || str == "inf" || str == "nan") {
        return true;
    }

    bool hasDigit = false;
    bool hasDecimal = false;
    bool hasExponent = false;
    bool hasF = false;
    size_t i = 0;

    if (str[i] == '-' || str[i] == '+') {
        i++;
        if (i == str.length()) return false;
    }

    for (; i < str.length(); ++i) {
        char c = str[i];

        if (c >= '0' && c <= '9') {
            hasDigit = true;
            continue;
        }

        if (c == '.') {
            if (hasDecimal || hasExponent || hasF)
                return false;
            hasDecimal = true;
            continue;
        }

        if (c == 'e' || c == 'E') {
            if (hasExponent || !hasDigit || hasF)
                return false;
            hasExponent = true;
            if (i+1 < str.length() && (str[i+1] == '+' || str[i+1] == '-')) {
                i++;
                if (i+1 >= str.length()) return false;
            }
            continue;
        }

        if (c == 'f') {
            if (i != str.length()-1 || !hasDigit)
                return false;
            hasF = true;
            continue;
        }

        return false;
    }

    return hasDigit && (!hasF || str[str.length()-1] == 'f');
}

bool convertFloat(int &_int, char &_char, float &_float, double &_double, const std::string &str) {
    if (!isFloat(str))
        return true;

    if (str == "-inff")
	{
		_float = -std::numeric_limits<float>::infinity();
		_double = -std::numeric_limits<float>::infinity();
		return (true);
	}
	else if (str == "+inff" || str == "inff")
	{
	    _float = std::numeric_limits<float>::infinity();
	    _double = std::numeric_limits<float>::infinity();
	    return (true);
	}
	else if (str == "nanf" || str == "NaNf" || str == "NANf" || str == "NANF")
	{
	    _float = std::numeric_limits<float>::quiet_NaN();
	    _double = std::numeric_limits<float>::quiet_NaN();
	    return (true);
	}
    double result = 0.0;
    double fraction = 1.0;
    int exponent = 0;
    int expSign = 1;
    bool isNeg = false, hasDecimal = false, hasExponent = false;
    size_t i = 0;

    if (str[i] == '-') { isNeg = true; i++; }
    else if (str[i] == '+') i++;

    for (; i < str.length(); ++i) {
        char c = str[i];
        
        if (c >= '0' && c <= '9') {
            if (hasExponent) {
                exponent = exponent * 10 + (c - '0');
            } else if (hasDecimal) {
                fraction *= 10.0;
                result += (c - '0') / fraction;
            } else {
                result = result * 10.0 + (c - '0');
            }
            continue;
        }

        if (c == '.') {
            if (hasDecimal || hasExponent) return true;
            hasDecimal = true;
            continue;
        }

        if (c == 'e' || c == 'E') {
            if (hasExponent) return true;
            hasExponent = true;
            if (i+1 < str.length() && str[i+1] == '-') { expSign = -1; i++; }
            else if (i+1 < str.length() && str[i+1] == '+') i++;
            continue;
        }

        if (c == 'f' || c == 'F') {
            if (i != str.length()-1) return true;
            break;
        }

        return true;
    }

    if (hasExponent) {
        result *= std::pow(10.0, expSign * exponent);
    }

    if (isNeg) result = -result;

    if (result > std::numeric_limits<float>::max()) {
        _float = std::numeric_limits<float>::infinity();
    } else if (result < -std::numeric_limits<float>::max()) {
        _float = -std::numeric_limits<float>::infinity();
    } else {
        _float = static_cast<float>(result);
    }

    _double = result;

    if (result > std::numeric_limits<int>::max() || 
        result < std::numeric_limits<int>::min() ||
        std::isnan(result)) {
        _int = 0;
        _char = 0;
    } else {
        _int = static_cast<int>(result);
        _char = (result >= 0 && result <= 127 && std::isfinite(result)) ? 
               static_cast<char>(result) : 0;
    }

    return false;
}
void printData(int _int, char _char, float _float, double _double, bool impossible)
{
    std::cout << "char: ";
    if (!impossible && std::isprint(_char))
		std::cout << "'" << _char << "'" << std::endl;
    else if (impossible)
		std::cout << "impossible" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    if (impossible)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << _int << std::endl;
    std::cout << "float: " << _float << "f" << std::endl;
    std::cout << "double: " << _double << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
    int _int = 0;
    char _char = 0;
    float _float = 0.0f;
    double _double = 0.0;
    bool impossible = false;
    bool displateable;

    if (isChar(str))
        impossible = convertChar(_int, _char, _float, _double, str, impossible, displateable);
        else if (isInt(str))
        impossible = convertInt(_int, _char, _float, _double, str, impossible);
        else if (isFloat(str))
            impossible = convertFloat(_int, _char, _float, _double, str);
        // else if (isDouble(str))
        //     impossible = convertDouble(_char, _int, _float, _double, str);
        else
        {
            std::cout << "Error: Invalid input" << std::endl;
            return;
        }

    printData(_int, _char, _float, _double, impossible);
}