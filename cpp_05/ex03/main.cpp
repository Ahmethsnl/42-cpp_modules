#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    AForm* form;

    // Test 1: Valid form creation
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        std::cout << "Form created successfully: " << form->getName() << std::endl;
        delete form;
    }

    // Test 2: Another valid form creation
    form = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (form) {
        std::cout << "Form created successfully: " << form->getName() << std::endl;
        delete form;
    }

    // Test 3: Invalid form creation
    form = someRandomIntern.makeForm("invalid form", "Target");
    if (!form) {
        std::cout << "Failed to create form." << std::endl;
    }

    return 0;
}
