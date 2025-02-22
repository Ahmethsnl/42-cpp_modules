#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n----------\n" << std::endl;

    Animal *a = new Cat;

	std::cout << "\n----------\n" << std::endl;

    Animal *b = new Dog;

	std::cout << "\n----------\n" << std::endl;

    a->makeSound();
    b->makeSound();

    std::cout << "\n----------\n" << std::endl;

    delete a;

	std::cout << "\n----------\n" << std::endl;

    delete b;
    // Animal animal;

	return 0;
}