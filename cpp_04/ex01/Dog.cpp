#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog created" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*copy.brain);
	this->type = copy.type;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destroyed" << std::endl;
}

Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
		delete this->brain;
		this->brain = new Brain(*copy.brain);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Bark bark bark bark" << std::endl;
}

void Dog::setDogIdea(std::string str)
{
	brain->setAllIdeas(str);
}

void Dog::printNidea(int i)
{
	this->brain->printNidea(i);
}

void Dog::printBrainAddress()
{
	std::cout << this->brain << std::endl;
}