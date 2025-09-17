#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), target(copy.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	if (this == &assign)
		return (*this);
	AForm::operator=(assign);
	target = assign.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	srand((unsigned)time(0));
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout << "* drilling noises *" << std::endl;
	if (rand() % 2)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << target << " robotomization failed." << std::endl;
}