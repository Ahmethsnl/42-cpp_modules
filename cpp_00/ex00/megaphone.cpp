/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:17:38 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/01 15:30:48 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    i = 0;
    while (argv[++i])
    {
        j = -1;
        while (argv[i][++j])
            std::cout << (char)std::toupper(argv[i][j]);
    }
    return 0;
}
