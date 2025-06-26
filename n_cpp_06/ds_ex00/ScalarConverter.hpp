#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <limits>

class ScalarConverter
{
    private:
        ScalarConverter ();
        ScalarConverter (const ScalarConverter &src);
        ~ScalarConverter ();
        ScalarConverter &operator=(const ScalarConverter &rhs);
    
    public:
        static void convert(const std::string &literal);
};

#endif