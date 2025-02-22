# include "ScavTrap.hpp"

int main()
{
	std::cout << "\n\033[34m### TESTING CLAPTRAP ###\033[0m\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m\n" << std::endl;
    
		ClapTrap a;
		ClapTrap b("Samet");
        ClapTrap c("At");
		ClapTrap d(c);

		std::cout << "\n\033[34mTesting\033[0m\n" << std::endl;

		a.attack("Migenc");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("miraç");
		b.beRepaired(3);
		for (int i = 0; i < 5; i++)
			b.attack("Clone");
		b.beRepaired(3);

		std::cout << "\n\033[34mDeconstructing\033[0m\n" << std::endl;
	}

	std::cout << "\n\033[34m### TESTING SCAVTRAP ###\033[0m\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m\n" << std::endl;
		ScavTrap c;
		ScavTrap d("Savage");

		std::cout << "\n\033[34mTesting\033[0m\n" << std::endl;
		c.attack("CloneTrap");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();
		d.attack("Savage-clone");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("ScavTrap-clone");
		std::cout << "\n\033[34mDeconstructing\033[0m\n" << std::endl;
	}
	return (0);
}