#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), target(copy.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	if (this == &assign)
		return (*this);
	AForm::operator=(assign);
	target = assign.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw AForm::AFormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream outfile ((target + "_shrubbery").c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return ;
	}
	outfile << "                ,@@@@@@@," << std::endl;
	outfile << "        ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	outfile << "     ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	outfile << "    ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	outfile << "    %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	outfile << "    %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	outfile << "    `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	outfile << "        |o|        | |         | |" << std::endl;
	outfile << "        |.|        | |         | |" << std::endl;
	outfile << "     \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	outfile.close();

	std::cout << "ShrubberyCreationForm has been executed by " << executor.getName() << std::endl;
}