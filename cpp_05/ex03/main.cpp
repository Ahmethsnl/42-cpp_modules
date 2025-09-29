#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    AForm* form;
    Bureaucrat highLevel("Boss", 1);
    
    std::cout << "=== INTERN TESTS ===" << std::endl;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        std::cout << "Form created successfully: " << form->getName() << std::endl;
        delete form;
    }

    form = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (form) {
        std::cout << "Form created successfully: " << form->getName() << std::endl;
        
        highLevel.signAForm(*form);
        highLevel.executeForm(*form);
        
        delete form;
    }

    form = someRandomIntern.makeForm("presidential pardon", "Arthur");
    if (form) {
        std::cout << "Form created successfully: " << form->getName() << std::endl;
        
        highLevel.signAForm(*form);
        highLevel.executeForm(*form);
        
        delete form;
    }

    form = someRandomIntern.makeForm("invalid form", "Target");
    if (!form) {
        std::cout << "Failed to create form." << std::endl;
    }

    return 0;
}
