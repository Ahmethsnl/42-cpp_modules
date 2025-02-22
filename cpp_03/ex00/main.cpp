#include "ClapTrap.hpp"

int main()
{
	std::cout << "\033[34m### TESTING CLAPTRAP ###\033[0m\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
    
		ClapTrap a;
		ClapTrap b("Samet");
        ClapTrap c("At");
		ClapTrap d(c);

		std::cout << "\033[34mTesting\033[0m" << std::endl;

		a.attack("Migenc");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("miraç");
		b.beRepaired(3);
		for (int i = 0; i < 5; i++)
			b.attack("Migenc-Clone");
		b.beRepaired(3);

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	return (0);
}