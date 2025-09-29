# include "AForm.hpp"

AForm::AForm() : name("default"), _signed(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : name(name), _signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &copy) : name(copy.name), _signed(copy._signed), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {}

AForm &AForm::operator=(AForm const &copy)
{
    if (this != &copy)
        _signed = copy._signed;
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return name; }

bool AForm::getSigned() const { return _signed; }

int AForm::getGradeToSign() const { return gradeToSign; }

int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    else if (_signed)
        throw AForm::AFormAlreadySignedException();
    _signed = true;
}

const char *AForm::GradeTooHighException::what() const throw() { return "Grade is too high"; }

const char *AForm::GradeTooLowException::what() const throw() { return "Grade is too low"; }

const char *AForm::AFormAlreadySignedException::what() const throw() { return "AForm is already signed"; }

const char *AForm::AFormNotSignedException::what() const throw() { return "AForm is not signed"; }

std::ostream &operator<<(std::ostream &out, AForm const &AForm)
{
    out << AForm.getName() << ", AForm signed status: " << AForm.getSigned() << ", grade to sign: " << AForm.getGradeToSign() << ", grade to execute: " << AForm.getGradeToExecute();
    return out;
}