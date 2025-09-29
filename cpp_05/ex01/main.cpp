# include "Form.hpp"
# include "Bureaucrat.hpp"

int main ()
{
    try
    {
        Bureaucrat b1("b1", 1);
        Bureaucrat b2("b2", 150);
        Form f1("f1", 1, 1);
        Form f2("f2", 150, 150);
        Form f3("f3", 1, 150);
        Form f4("f4", 150, 1);
        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;
        std::cout << f4 << std::endl;
        b1.signForm(f1);
        b2.signForm(f2);
        b1.signForm(f2);
        b2.signForm(f1);
        b1.signForm(f3);
        b2.signForm(f4);
        b1.signForm(f4);
        b2.signForm(f3);
        
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}