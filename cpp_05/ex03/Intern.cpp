#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createRobotomyRequest(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreation(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createPresidentialPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    struct FormPair {
        std::string name;
        AForm* (*create)(const std::string&);
    };

    FormPair forms[] = {
        {"robotomy request", &Intern::createRobotomyRequest},
        {"shrubbery creation", &Intern::createShrubberyCreation},
        {"presidential pardon", &Intern::createPresidentialPardon}
    };

    for (size_t i = 0; i < sizeof(forms) / sizeof(FormPair); ++i) {
        if (forms[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }

    std::cerr << "Error: Form name \"" << formName << "\" does not exist." << std::endl;
    return nullptr;
}
