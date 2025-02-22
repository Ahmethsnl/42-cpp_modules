#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class   Zombie
{
    private:
	    std::string name;
    
    public:
	    Zombie();
	    ~Zombie();
	    Zombie(std::string name);
	    void	announce(void);
		void	setZombieName(std::string name);
};

	Zombie* zombieHorde(int N, std::string name);
	void	deleteHorde(Zombie *zombieWHorde);

#endif