#include "Contact.hpp"

void Contact::setFirstName(std::string setFirstName)
{
    this->firstName = setFirstName;
}

void Contact::setLastName(std::string setLastName)
{
    this->lastName = setLastName;
}

void Contact::setNickName(std::string setNickName)
{
    this->nickName = setNickName;
}

void Contact::setPhoneNumber(std::string setPhoneNumber)
{
    this->phoneNumber = setPhoneNumber;
}

void Contact::setDarkSecret(std::string setDarkSecret)
{
    this->darkSecret = setDarkSecret;
}

void Contact::getData()
{
    getNameHelper();
    getPhoneNumberHelper();
    getDarkSecretHelper();
    std::cin.clear();
}
