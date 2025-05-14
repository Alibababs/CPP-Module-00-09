#include "Bureaucrat.hpp"

int main( void )
{
    /// TOO HIGH
    std::cout << "----- TOO HIGH TEST -----" << std::endl;
    try
    {
        Bureaucrat michel("Michel", 151);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    /// TOO LOW
    std::cout << "----- TOO LOW TEST -----" << std::endl;
    try
    {
        Bureaucrat michel("Michel", -42);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    /// INCREMENT TEST
    std::cout << "----- INCREMENT TEST -----" << std::endl;
    try
    {
        Bureaucrat michel("Michel", 1);
        michel.incrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    /// DECREMENT TEST
    std::cout << "----- DECREMENT TEST -----" << std::endl;
    try
    {
        Bureaucrat michel("Michel", 150);
        michel.decrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    /// WORKING
    std::cout << "----- WORKING TEST -----" << std::endl;
    try
    {
        Bureaucrat michel("Michel", 42);
        michel.incrementGrade();
        michel.decrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}
