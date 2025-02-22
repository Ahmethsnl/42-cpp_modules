#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    public:
        void highFivesGuys(void);
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& src);
        ~FragTrap();
        FragTrap &operator=(FragTrap &src);
};