/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:08:27 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/05 18:11:59 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie zombie("Foo");
	zombie.announce();
	Zombie *zombie2 = newZombie("The Cranberries");
	zombie2->announce();
	randomChump("Music");
	delete zombie2;
}