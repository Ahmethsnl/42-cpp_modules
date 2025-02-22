#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called!" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << "Cat copy constructor called!" << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout << "Cat copy assigment called!" << std::endl;
    this->type = src.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}
