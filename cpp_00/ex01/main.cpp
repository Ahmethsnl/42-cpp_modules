#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phoneBook;
	std::string	entry;

	while (1)
	{
		std::cout << "ADD SEARCH or EXIT" << std::endl;
		std::cin >> entry;
		if (std::cin.eof())
			break ;
		if (entry == "ADD")
		{
			std::cin.ignore();
			phoneBook.addDataPhone();
		}
		else if (entry == "SEARCH")
			phoneBook.searchDataPhone();
		else if (entry == "EXIT")
			break ;
	}
}