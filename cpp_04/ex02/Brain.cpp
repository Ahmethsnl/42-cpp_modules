#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain created" << std::endl;
	this->ideas = new std::string[100];
}

Brain::Brain(const Brain& ref)
{
	std::cout << "Brain copy constructor called" << std::endl;
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ref.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain destroyed" << std::endl;
	delete[] this->ideas;
}

Brain& Brain::operator=(const Brain& copy)
{
	std::cout << "Brain's copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		delete[] this->ideas;
		this->ideas = new std::string[100];
		for (int i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
	}
	return *this;
}

void Brain::setAllIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = idea;
}

void Brain::printNidea(int i)
{
	if (i < 0 || i > 99)
		return;
	for (int j = 0; j < i; j++)
		std::cout << j + 1 << " Idea : " << this->ideas[j] << std::endl;
}
