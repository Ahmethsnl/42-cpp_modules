#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void)
{
    std::cout << "Do you want a high five?" << std::endl;
}
    
FragTrap::FragTrap(): ClapTrap()
{
    this->name = "Basic FragTrap";
    this->attackDamage = 30;
    this->energyPoints = 100;
    this->hitPoints = 100;
    std::cout << "a FRAGTRAP Instance has created with default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->name = name;
    this->attackDamage = 30;
    this->energyPoints = 100;
    this->hitPoints = 100;
    std::cout << "a FRAGTRAP Instance has created with default constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy): ClapTrap(copy)
{
    std::cout << "a FragTrap instance created with copy constructor." << std::endl;
}

FragTrap::~FragTrap()
{
        std::cout << "a FRAGTRAP Instance destroyed with deconstructor" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &src)
{
    std::cout << "FlagTrap copy assignment operator called" << std::endl;
    this->name = src.name;
    this->hitPoints = src.hitPoints;
    this->attackDamage = src.attackDamage;
    this->energyPoints = src.energyPoints;
    return *this;
}