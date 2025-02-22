/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:08:04 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/05 17:33:04 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::~HumanB(){}

HumanB::HumanB(const std::string& name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
    this->isArmed = "Armed";
}

void	HumanB::attack()
{
	if(!((this->isArmed).empty()))
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " doesn't have a weapon right now" << std::endl;
}