#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const name;
        bool _signed;
        int const gradeToSign;
        int const gradeToExecute;
    public:
        Form();
        Form(std::string const name, int gradeToSign, int gradeToExecute);
        Form(Form const &copy);
        Form &operator=(Form const &copy);
        ~Form();

        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(Bureaucrat const &bureaucrat);

        class GradeTooHighException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };

        class FormAlreadySignedException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif