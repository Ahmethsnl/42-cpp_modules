#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->idx = 0;
	std::cout << "Welcome to PhoneBook" << std::endl;	
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Exit" << std::endl;
}

void	PhoneBook::addDataPhone(void)
{
	this->contact[this->idx % 8].getData();
	if (this->contact[this->idx % 8].getFirstName().size() && this->contact[this->idx % 8].getLastName().size() && this->contact[this->idx % 8].getNickName().size() && this->contact[this->idx % 8].getPhoneNumber().size() && this->contact[this->idx % 8].getDarkSecret().size())
		this->idx++;
}

void	PhoneBook::searchDataPhone(void)
{
	int			i;
	int			control;
	std::string	entry;

	i = -1;
	if (this->idx == 0)
	{
		std::cout << "No contacts" << std::endl;
		return ;
	}
	if (this->idx > 7)
		control = 8;
	else
		control = this->idx;
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (++i < control)
		this->contact[i].searchData(i);
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "Enter an index ";
	std::cin >> entry;
	while (!(entry.length() == 1 && std::isdigit(entry[0]) && entry[0] - '0' < (this->idx < 8 ? this->idx : 8) && this->contact[entry[0] - '0'].getFirstName().size()))
	{
		std::cout << "invalid index " + entry +". New index: ";
		std::cin >> entry;
	}
	this->contact[entry[0] - '0'].putData();
}
