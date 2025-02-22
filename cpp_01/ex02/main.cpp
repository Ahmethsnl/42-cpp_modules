/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:08:14 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/05 15:07:45 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string obj = "HI THIS IS BRAIN";
	std::string* stringPTR = &obj;
	std::string& stringREF = obj;

	std::cout << "Address of the string: " << &obj<< std::endl;
	std::cout << "Address of the string using pointer: " << stringPTR << std::endl;
	std::cout << "Address of the string using reference: " << &stringREF << std::endl;

	std::cout << "String: " << obj<< std::endl;
	std::cout << "String using pointer: " << *stringPTR << std::endl;
	std::cout << "String using reference: " << stringREF << std::endl;

}