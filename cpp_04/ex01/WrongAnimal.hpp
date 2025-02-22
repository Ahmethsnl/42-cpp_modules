#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		virtual ~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& copy);
		std::string getType() const;
		void makeSound() const;
};

#endif