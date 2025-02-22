/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:08:21 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/05 15:38:34 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Zombie Created" << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << this->name << " Created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << " existence erased" << std::endl;
}

void Zombie::setZombieName(std::string name)
{
	this->name = name;
}

void    Zombie::announce(void)
{
    std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void deleteHorde(Zombie* zombieWHorde)
{
    delete[] zombieWHorde;
}