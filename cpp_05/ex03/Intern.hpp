#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target);

private:
    static AForm* createRobotomyRequest(const std::string& target);
    static AForm* createShrubberyCreation(const std::string& target);
    static AForm* createPresidentialPardon(const std::string& target);
};

#endif
