#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const name;
        bool _signed;
        int const gradeToSign;
        int const gradeToExecute;
    public:
        AForm();
        AForm(std::string const name, int gradeToSign, int gradeToExecute);
        AForm(AForm const &copy);
        AForm &operator=(AForm const &copy);
        virtual ~AForm();

        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(Bureaucrat const &bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;

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

        class AFormAlreadySignedException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };

        class AFormNotSignedException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, AForm const &Aform);

#endif