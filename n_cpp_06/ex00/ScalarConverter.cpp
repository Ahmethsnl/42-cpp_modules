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

int isChar(const std::string &str)
{
    if (str.length() == 1 && !std::isdigit(str[0]))
        return 1;
    return 0;
}

bool convertChar(int &_int , char &_char, float &_float, double &_double, const std::string &str, bool &impossible)
{
    _char = str[0];
    if (isChar(str))
    {
        if (!std::isprint(_char))
            impossible = true;
        if (impossible)
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

int isInt(const std::string &str)
{
    if (str.empty())
        return 0;
    else if (str.length() == 1 && !std::isdigit(str[0]))
        return 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return 0;
    }
    return 1;
}

bool convertInt(int &_int , char &_char, float &_float, double &_double, const std::string &str, bool &impossible)
{
    long long res = 0;
    bool isNegative = false;
    size_t i = 0;
    if (str[0] == '-')
    {
        isNegative = true;
        i = 1;
    }
    else if (str[0] == '+')
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
    if (res > std::numeric_limits<int>::max() || res < std::numeric_limits<int>::min())
    {
        impossible = true;
        return impossible;
    }
    _int = res;
    _char = static_cast<char>(_int);
    _float = static_cast<float>(_int);
    _double = static_cast<double>(_int);
    return false;
}

int isFloat(const std::string &str)
{
	if (str.empty())
		return false;
	if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf" || str == "NaNf" || str == "NANf" || str == "NANF")
		return 1;

	bool hasDecimal = false;
	bool hasExponent = false;
	bool hasDigitsBefore = false;
	bool hasDigitsAfter = false;
	bool inExponent = false;

	size_t i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str.length() == 1)
			return false;
		i++;
	}

	for (size_t j = i; j < str.length(); ++j)
	{
		char c = str[j];

		if (std::isdigit(c))
		{
			if (inExponent)
				hasDigitsAfter = true;
			else
				hasDigitsBefore = true;
		}
		else if (c == '.')
		{
			if (hasDecimal || hasExponent)
				return false;
			hasDecimal = true;
		}
		else if (c == 'e' || c == 'E')
		{
			if (hasExponent || !hasDigitsBefore)
				return false;
			hasExponent = true;
			inExponent = true;
		}
		else if (c == '-' || c == '+')
		{
			if (j == i || (str[j - 1] != 'e' && str[j - 1] != 'E'))
				return false;
		}
		else if (c == 'f' || c == 'F')
        {
	        if (j != str.length() - 1 || !(hasDigitsBefore || hasDigitsAfter))
		    return false;
        }
		else
			return false;
	}

	if (hasExponent)
		return hasDigitsBefore && hasDigitsAfter;

	return hasDigitsBefore;
}

bool convertFloat(int &_int , char &_char, float &_float, double &_double, const std::string &str)
{
    if (isFloat(str))
    {
            float	result = 0.0f;
	    float	divisor = 1.0f;
	    bool	isNegative = false;
	    bool	isExponentNegative = false;
	    bool	inFraction = false;
	    bool	inExponent = false;
	    float	exponent = 0.0f;
	    size_t	i = 0;

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

        if (str[0] == '-')
	    {
		    isNegative = true;
		    i = 1;
	    }
	    else if (str[0] == '+')
		    i = 1;
        for (; i < str.length(); ++i)
        {
            if (std::isdigit(str[i]))
            {
                if (inExponent)
                    exponent = exponent * 10.0f + (str[i] - '0');
                else if (inFraction)
                {
                    divisor *= 10.0f;
                    result += (str[i] - '0') / divisor;
                }
                else
                    result = result * 10.0f + (str[i] - '0');
            }
            else if (str[i] == '.')
                inFraction = true;
            else if (str[i] == 'e' || str[i] == 'E')
                inExponent = true;
            else if (str[i] == '-')
                isExponentNegative = true;
            else if (str[i] == '+')
                isExponentNegative = false;
        }
        if (isExponentNegative)
            exponent = -exponent;
        result *= std::pow(10.0f, exponent);
        if (isNegative)
            result = -result;
        _char = static_cast<char>(result);
	    _int = static_cast<int>(result);
	    _float = result;
	    _double = static_cast<double>(result);
        return (false);
    }
    return false;
}

bool isDouble (const std::string &str)
{
    if (str.empty())
        return false;
    if (str == "-inf" || str == "+inf" || str == "inf" || str == "nan" || str == "NaN" || str == "NAN")
        return true;

    bool hasDecimal = false;
    bool hasExponent = false;
    bool hasDigitsBefore = false;
    bool hasDigitsAfter = false;
    bool inExponent = false;

    size_t i = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str.length() == 1)
            return false;
        i++;
    }

    for (size_t j = i; j < str.length(); ++j)
    {
        char c = str[j];

        if (std::isdigit(c))
        {
            if (inExponent)
                hasDigitsAfter = true;
            else
                hasDigitsBefore = true;
        }
        else if (c == '.')
        {
            if (hasDecimal || hasExponent)
                return false;
            hasDecimal = true;
        }
        else if (c == 'e' || c == 'E')
        {
            if (hasExponent || !hasDigitsBefore)
                return false;
            hasExponent = true;
            inExponent = true;
        }
        else if (c == '-' || c == '+')
        {
            if (j == i || (str[j - 1] != 'e' && str[j - 1] != 'E'))
            return false;
        }
        else
            return false;
    }
    if (hasExponent)
        return hasDigitsBefore && hasDigitsAfter;
    return hasDigitsBefore;
}

bool convertDouble(int &_int , char &_char, float &_float, double &_double, const std::string &str)
{
    if (isDouble(str))
    {
        double	result = 0.0;
        double	divisor = 1.0;
        bool	isNegative = false;
        bool	isExponentNegative = false;
        bool	inFraction = false;
        bool	inExponent = false;
        double	exponent = 0.0;
        size_t	i = 0;

        if (str == "-inf")
        {
            _float = -std::numeric_limits<double>::infinity();
            _double = -std::numeric_limits<double>::infinity();
            return (true);
        }
        else if (str == "+inf" || str == "inf")
        {
        	_float = std::numeric_limits<double>::infinity();
        	_double = std::numeric_limits<double>::infinity();
        	return (true);
        }
        else if (str == "nan" || str == "NaN" || str == "NAN")
        {
        	_float = std::numeric_limits<double>::quiet_NaN();
        	_double = std::numeric_limits<double>::quiet_NaN();
        	return (true);
        }

        if (str[0] == '-')
        {
            isNegative = true;
            i = 1;
        }
        else if (str[0] == '+')
            i = 1;
        for (; i < str.length(); ++i)
        {
            if (std::isdigit(str[i]))
            {
                if (inExponent)
                    exponent = exponent * 10.0 + (str[i] - '0');
                else if (inFraction)
                {
                    divisor *= 10.0;
                    result += (str[i] - '0') / divisor;
                }
                else
                    result = result * 10.0 + (str[i] - '0');
            }
            else if (str[i] == '.')
                inFraction = true;
            else if (str[i] == 'e' || str[i] == 'E')
                inExponent = true;
            else if (str[i] == '-')
                isExponentNegative = true;
            else if (str[i] == '+')
                isExponentNegative = false;
        }
        if (isExponentNegative)
            exponent = -exponent;
        if (exponent > 0)
            for (int e = 0; e < exponent; ++e) result *= 10.0;
        else
            for (int e = 0; e > exponent; --e) result /= 10.0;
        if (isNegative)
            result = -result;
        if (result >= static_cast<double>(std::numeric_limits<int>::max()) ||
            result <= static_cast<double>(std::numeric_limits<int>::min()) ||
            std::isnan(result))
            _int = 0;
        else
            _int = static_cast<int>(result);
        if (result < 0 || result > 127 || std::isnan(result) || !std::isprint(static_cast<char>(result)))
            _char = 0;
        else
            _char = static_cast<char>(result);
        return (false);
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

void	ScalarConverter::convert(const std::string &str)
{
	int	_int = 0;
	float	_float = 0.0f;
	double	_double = 0.0;
	char	_char = 0;
	bool impossible = false;
	if (isChar(str))
        	impossible = convertChar(_int, _char, _float, _double, str, impossible);
	else if (isInt(str))
        	impossible = convertInt(_int, _char, _float, _double, str, impossible);
	else if (isFloat(str))
		impossible = convertFloat(_int, _char, _float, _double, str);
	else if (isDouble(str))
		impossible = convertDouble(_int, _char, _float, _double, str);
	else
	{
		std::cout << "Error: Invalid input" << std::endl;
		return ;
	}
	printData(_int, _char, _float, _double, impossible);
}
