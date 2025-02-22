#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat created" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destroyed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	std::cout << "Wrong Cat copy assigment operator called" << std::endl;
    this->type = copy.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
}