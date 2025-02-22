#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat created" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	this->type = copy.type;
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*copy.brain);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat has been destroyed!" << std::endl;
}

Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "Cat copy assigment operator has been called!" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
		delete this->brain;
		this->brain = new Brain(*copy.brain);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}

void Cat::setCatIdea(std::string str)
{
	brain->setAllIdeas(str);
}

void Cat::printIdea(int i)
{
	this->brain->printNidea(i);
}

void Cat::printBrainAddress()
{
	std::cout << this->brain << std::endl;
}