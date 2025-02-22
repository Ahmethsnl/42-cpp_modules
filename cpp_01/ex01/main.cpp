/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:08:18 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/04 18:08:18 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie zombie("The Cranberries");
	zombie.announce();
	Zombie* zombieWHorde = zombieHorde(3, "Zombie");
	deleteHorde(zombieWHorde);
	return (0);
}