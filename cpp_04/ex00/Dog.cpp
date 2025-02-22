#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called!" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& src) : Animal(src)
{
	std::cout << "Dog copy constructor called!" << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << "Dog copy assigment called!" << std::endl;
    this->type = src.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Bark bark bark bark" << std::endl;
}