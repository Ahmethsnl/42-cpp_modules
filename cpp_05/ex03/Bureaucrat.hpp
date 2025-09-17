#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        std::string const name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &copy);
        Bureaucrat &operator=(Bureaucrat const &copy);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signAForm(AForm &Aform);

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
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif