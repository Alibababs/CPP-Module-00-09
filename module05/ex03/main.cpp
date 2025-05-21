#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main( void )
{
    std::cout << "---- MAIN TEST WORKING -----" << std::endl;

    Intern someRandomIntern;
    AForm* rrf;
    Bureaucrat michel("Michel", 1);

    try
    {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        michel.signForm(*rrf);
        michel.executeForm(*rrf);

        delete rrf;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "---- MAIN TEST ERROR -----" << std::endl;

    AForm* badForm;
    
    try 
    {
        badForm = someRandomIntern.makeForm("NOT WORKING", "Debilus");
        delete badForm;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
