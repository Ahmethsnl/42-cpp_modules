#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
        ScalarConverter::convert(av[1]);
	    return 0;
	}
    std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
}