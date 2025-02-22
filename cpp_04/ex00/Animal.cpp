#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called!" << std::endl;
	this->type = "Random Creature";
}

Animal::Animal(const Animal& src)
{
	std::cout << "Animal copy constructor called!" << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called!" << std::endl;
}

Animal& Animal::operator=(const Animal& src)
{
	std::cout << "Animal copy assigment called!" << std::endl;
    this->type = src.type;
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
