#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n----------\n" << std::endl;

    const WrongAnimal* wrongAn = new WrongAnimal();

    std::cout << "\n----------\n" << std::endl;

    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "\n----------\n" << std::endl;

    std::cout << wrongAn->getType() << " " << std::endl;

    wrongAn->makeSound();

    std::cout << "\n----------\n" << std::endl;

    std::cout << wrongCat->getType() << " " << std::endl;

    wrongCat->makeSound();

    std::cout << "\n----------\n" << std::endl;

    delete wrongAn;

    std::cout << "\n----------\n" << std::endl;

    delete wrongCat;

    std::cout << "\n----------\n" << std::endl;

    const Animal* meta = new Animal();

	std::cout << "\n----------\n" << std::endl;

    const Animal* j = new Dog();

	std::cout << "\n----------\n" << std::endl;

    const Animal* i = new Cat();

	std::cout << "\n----------\n" << std::endl;

    std::cout << j->getType() << " " << std::endl;

    j->makeSound();

	std::cout << "\n----------\n" << std::endl;

    std::cout << i->getType() << " " << std::endl;

    i->makeSound();

	std::cout << "\n----------\n" << std::endl;

    std::cout << meta->getType() << " " << std::endl;
    meta->makeSound();

	std::cout << "\n----------\n" << std::endl;

    delete i;

	std::cout << "\n----------\n" << std::endl;

    delete j;

	std::cout << "\n----------\n" << std::endl;

    delete meta;

	std::cout << "\n----------\n" << std::endl;
    
    return 0;
}