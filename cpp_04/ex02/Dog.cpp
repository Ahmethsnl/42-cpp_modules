#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog created" << std::endl;
	this->type = "Dog";
	this->br = new Brain();
}

Dog::Dog(const Dog& ref) : Animal(ref)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->br = new Brain(*ref.br);
	this->type = ref.type;
}

Dog::~Dog()
{
	delete this->br;
	std::cout << "Dog destroyed" << std::endl;
}

Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "Dog copy assignment operator called!" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
		delete this->br;
		this->br = new Brain(*copy.br);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Bark bark bark bark" << std::endl;
}

void Dog::setDogIdea(std::string str)
{
	br->setAllIdeas(str);
}

void Dog::printNidea(int i)
{
	this->br->printNidea(i);
}

void Dog::printBrainAddress()
{
	std::cout << this->br << std::endl;
}