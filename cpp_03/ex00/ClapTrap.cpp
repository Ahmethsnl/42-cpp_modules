# include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->name = "ClapTrap";
    this->hitPoints = 10;    
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hitPoints = 10;    
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    std::cout << "ClapTrap copy assignation operator called" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
    if(this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->energyPoints -= 1;
        std::cout << "ClapTrap " << this->name << " attacks to " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
    }
    else if(this->hitPoints <= 0)
        std::cout << "ClapTrap " << this->name << " unable to attack—status: dead." << std::endl;
    else if(this->energyPoints <= 0)
        std::cout << "ClapTrap " << this->name << " doesn't have sufficient energy to execute an attack " << target << std::endl; 
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->hitPoints <= 0)
        std::cout << this->name << " is already dead." << std::endl;
    else
        std::cout << "ClapTrap " << this->name << " took " << amount << " damage." << std::endl;
    if((this->hitPoints - amount) <= 0)
        this->hitPoints = 0;
    else
        this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->hitPoints <= 0)
        std::cout << "ClapTrap " << this->name << " cannot initiate self-repair—status: terminated." << std::endl;
    else if(this->energyPoints <= 0)
        std::cout << "ClapTrap " << this->name << " lacks the necessary energy for self-repair." << std::endl;
    else 
    {
        this->energyPoints -= 1;
        this->hitPoints += amount;
        std::cout << "ClapTrap " << this->name << " repaired " << amount << " hit points, it has " << this->hitPoints << " hit points now." << std::endl;
    } 
}