# include "Form.hpp"

Form::Form() : name("default"), _signed(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : name(name), _signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &copy) : name(copy.name), _signed(copy._signed), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {}

Form &Form::operator=(Form const &copy)
{
    if (this != &copy)
        _signed = copy._signed;
    return *this;
}

Form::~Form() {}

std::string Form::getName() const { return name; }

bool Form::getSigned() const { return _signed; }

int Form::getGradeToSign() const { return gradeToSign; }

int Form::getGradeToExecute() const { return gradeToExecute; }

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    else if (_signed)
        throw Form::FormAlreadySignedException();
    _signed = true;
}

const char *Form::GradeTooHighException::what() const throw() { return "Grade is too high"; }

const char *Form::GradeTooLowException::what() const throw() { return "Grade is too low"; }

const char *Form::FormAlreadySignedException::what() const throw() { return "Form is already signed"; }

std::ostream &operator<<(std::ostream &out, Form const &form)
{
    out << form.getName() << ", form signed status: " << form.getSigned() << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
    return out;
}
