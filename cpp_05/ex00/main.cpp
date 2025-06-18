# include "Bureaucrat.hpp"

int main()
{
    Bureaucrat bureaucrat("John", 150);
    std::cout << bureaucrat << std::endl;

    std::cout << "John with 0" << std::endl;

    try
    {
        Bureaucrat bureaucrat("John", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "John with 151" << std::endl;

    try
    {
        Bureaucrat bureaucrat("John", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "John with loop" << std::endl;

    try
    {
        Bureaucrat bureaucrat("John", 10);
        for (int i = 0; i < 10; i++)
        {
            bureaucrat.incrementGrade();
            std::cout << bureaucrat << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}