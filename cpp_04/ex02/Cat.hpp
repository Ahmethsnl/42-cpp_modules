#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain *br;
	public:
		Cat();
		Cat(const Cat& ref);
		~Cat();
		Cat& operator=(const Cat& ref);
		void makeSound() const;
		void setCatIdea(std::string str);
		void printIdea(int i);
		void printBrainAddress();
};


#endif