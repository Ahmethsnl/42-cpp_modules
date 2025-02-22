#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat created" << std::endl;
	this->type = "Cat";
	this->br = new Brain();
}

Cat::Cat(const Cat& ref) : Animal(ref)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->br = new Brain(*ref.br);
	this->type = ref.type;
}

Cat::~Cat()
{
	delete this->br;
	std::cout << "Cat destroyed" << std::endl;
}

Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "Cat copy assigment operator called" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
		delete this->br;
		this->br = new Brain(*copy.br);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}

void Cat::setCatIdea(std::string str)
{
	br->setAllIdeas(str);
}

void Cat::printIdea(int i)
{
	this->br->printNidea(i);
}

void Cat::printBrainAddress()
{
	std::cout << this->br << std::endl;
}