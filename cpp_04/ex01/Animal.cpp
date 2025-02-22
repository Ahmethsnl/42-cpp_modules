#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal created" << std::endl;
	this->type = "Random creature";
}

Animal::Animal(const Animal& copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal destroyed" << std::endl;
}

Animal& Animal::operator=(const Animal& copy)
{
	std::cout << "Animal copy assigment operator called" << std::endl;
    this->type = copy.type;
	return (*this);
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
