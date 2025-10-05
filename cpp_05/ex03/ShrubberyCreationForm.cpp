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
	outfile << "           /\\  " << std::endl;
	outfile << "          /  \\ " << std::endl;
	outfile << "         /____\\" << std::endl;
	outfile << "        /      \\" << std::endl;
	outfile << "       /   /\\   \\" << std::endl;
	outfile << "      /   /  \\   \\" << std::endl;
	outfile << "     /___/____\\___\\" << std::endl;
	outfile << "    /              \\" << std::endl;
	outfile << "   /     FOREST     \\" << std::endl;
	outfile << "  /   OF SHRUBBERY   \\" << std::endl;
	outfile << " /____________________\\" << std::endl;
	outfile << "         |    |" << std::endl;
	outfile << "         |    |" << std::endl;
	outfile << "     ____|____|____" << std::endl;
	outfile.close();

	std::cout << "ShrubberyCreationForm has been executed by " << executor.getName() << std::endl;
}