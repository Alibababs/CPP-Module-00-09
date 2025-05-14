#include "Bureaucrat.hpp"

int main( void )
{
    try
    {
        Bureaucrat coucou("coucou", 151);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}