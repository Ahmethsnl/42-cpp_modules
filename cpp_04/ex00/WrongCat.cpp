#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat created" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destroyed!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
	std::cout << "WrongCat copy called" << std::endl;
    this->type = src.type;
    return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
}