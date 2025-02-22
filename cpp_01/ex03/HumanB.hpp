#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
	std::string name;
	Weapon* weapon;

	public:
    std::string isArmed;
	~HumanB();
	HumanB(const std::string& name);
	void setWeapon(Weapon& weapon);
	void attack();
};

#endif