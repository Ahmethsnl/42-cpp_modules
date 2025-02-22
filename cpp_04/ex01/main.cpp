#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n----------\n" << std::endl;

	Dog *i = new Dog();
	i->setDogIdea("migencat");

	Dog meta = *i;
	Dog *a = i;

	std::cout << "\n----------" << std::endl;

	std::cout << "\nDeepCopy\n" << std::endl;
	i->printBrainAddress();
	meta.printBrainAddress();

	std::cout << "\n----------" << std::endl;

	std::cout << "\nShallowCopy\n" << std::endl;
	a->printBrainAddress();
	i->printBrainAddress();
	std::cout << "\n----------\n" << std::endl;

	delete i;

	std::cout << "\n----------\n" << std::endl;

	const int arraySize = 10;
    Animal* animals[arraySize];

    for (int i = 0; i < arraySize / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = arraySize / 2; i < arraySize; ++i) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < arraySize; ++i) {
        delete animals[i];
    }

	return 0;
}