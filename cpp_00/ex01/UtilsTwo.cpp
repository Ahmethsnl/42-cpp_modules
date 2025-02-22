#include "Contact.hpp"

void Contact::getNameHelper()
{
    std::cout << "Enter First Name: ";
    getline(std::cin, this->firstName);
    if (this->firstName.empty())
    {
        std::cout << "First name cannot be empty" << std::endl;
        std::cin.clear();
        return ;
    }
    std::cout << "Enter Last Name ";
    getline(std::cin, this->lastName);
    if (this->lastName.empty())
    {
        std::cout << "Last name cannot be empty" << std::endl;
        std::cin.clear();
        return ;
    }
    std::cout << "Enter Nick Name ";
    getline(std::cin, this->nickName);
    if (this->nickName.empty())
    {
        std::cout << "Nick name cannot be empty" << std::endl;
        std::cin.clear();
        return ;
    }
}

void Contact::getPhoneNumberHelper()
{
    std::cout << "Enter Phone Number: ";
    getline(std::cin, this->phoneNumber);
    if (this->phoneNumber.empty())
    {
        std::cout << "Phone Number cannot be empty" << std::endl;
        std::cin.clear();
        return ;
    }
}

void Contact::getDarkSecretHelper()
{
    std::cout << "Enter Dark Secret: ";
    getline(std::cin, this->darkSecret);
    if (this->darkSecret.empty())
    {
        std::cout << "Dark Secret cannot be empty " << std::endl;
        std::cin.clear();
        return ;
    }
}
