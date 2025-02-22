/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:08:01 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/05 15:08:47 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::~HumanA(){}

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon){}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}