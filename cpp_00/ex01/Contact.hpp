#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "iostream"
#include "string"

class Contact
{
    	private :
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkSecret;
        void getNameHelper();
        void getPhoneNumberHelper();
        void getDarkSecretHelper();

        public :
        void setFirstName(std::string setFirstName);
        void setLastName(std::string setLastName);
        void setNickName(std::string setNickName);
        void setPhoneNumber(std::string setPhoneNumber);
        void setDarkSecret(std::string setDarkSecret);
        void getData();
        void putData();
        void searchData(int i);
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getDarkSecret();
};

#endif