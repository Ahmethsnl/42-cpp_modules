/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:08:23 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/05 14:14:06 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    int i = 0;
    Zombie* horde = new Zombie[N];
    
    while (i < N)
    {
        horde[i].setZombieName(name);
        horde[i].announce();
        i++;
    }
    return horde;
}