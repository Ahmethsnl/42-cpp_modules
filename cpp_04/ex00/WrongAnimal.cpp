#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Wrong Animal created" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	std::cout << "Wrong Animal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destroyed" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src)
{
	std::cout << "Wrong Animal copy assigment operator called!" << std::endl;
	this->type = src.type;
    return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}
