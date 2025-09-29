# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{
    ShrubberyCreationForm* shrubbery = new ShrubberyCreationForm("shrubbery");
    RobotomyRequestForm* robotomy = new RobotomyRequestForm("robotomy");
    PresidentialPardonForm* presidential = new PresidentialPardonForm("presidential");

    Bureaucrat b1("b1", 1);
    Bureaucrat b2("b2", 150);

    std::cout << *shrubbery << std::endl;
    std::cout << *robotomy << std::endl;
    std::cout << *presidential << std::endl;

    shrubbery->beSigned(b1);
    robotomy->beSigned(b1);
    presidential->beSigned(b1);

    try {
        shrubbery->execute(b1);
        robotomy->execute(b1);
        presidential->execute(b1);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        shrubbery->execute(b2);
        robotomy->execute(b2);
        presidential->execute(b2);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    delete shrubbery;
    delete robotomy;
    delete presidential;

    return 0;
}