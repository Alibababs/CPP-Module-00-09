#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
    /// CAN'T SIGN
    std::cout << "----- CAN'T SIGN -----" << std::endl;

    Form form("F42", 42, 42);

    std::cout << form << std::endl;

    Bureaucrat michel("Michel", 43);

    michel.signForm(form);

    std::cout << form << std::endl;

    /// CAN SIGN
    std::cout << "----- CAN SIGN -----" << std::endl;

    michel.incrementGrade();

    michel.signForm(form);

    std::cout << form << std::endl;
}
