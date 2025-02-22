#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool guardingGate;
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &src);
		void attack(const std::string &target);
		void guardGate(void);
};

#endif