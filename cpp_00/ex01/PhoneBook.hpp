#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "iostream"
#include "Contact.hpp"

# define MAX_CONT 8

class PhoneBook
{
	private:
		int		idx;
		Contact	contact[8];
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addDataPhone(void);
		void	searchDataPhone(void);
};

#endif