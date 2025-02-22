#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	private:
		Brain *br;
	public:
		Dog();
		Dog(const Dog& ref);
		~Dog();
		Dog& operator=(const Dog& ref);
		void makeSound() const;
		void setDogIdea(std::string str);
		void printNidea(int i);
		void printBrainAddress();
};

#endif