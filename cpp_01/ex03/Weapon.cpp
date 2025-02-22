/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:08:10 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/05 17:34:58 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::~Weapon(){}

Weapon::Weapon(const std::string type)
{
	this->type = type;
}

const std::string& Weapon::getType()
{
	return this->type;
}

void Weapon::setType(const std::string& type)
{
	this->type = type;
}