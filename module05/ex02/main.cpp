#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main( void )
{
    ShrubberyCreationForm tree("Tree Form");
    PresidentialPardonForm pardon("Pardon Form");
    RobotomyRequestForm robot("Robot Form");

    Bureaucrat michel("Michel", 1);
    Bureaucrat debilus("Gros debile", 150);

    std::cout << "" << std::endl;
    std::cout << "----- MICHEL GRADE 1 WORKING ------" << std::endl;
    std::cout << "" << std::endl;

    std::cout << "--- TREE FORM ---" << std::endl;

    michel.signForm(tree);
    michel.executeForm(tree);

    std::cout << "--- PARDON FORM ---" << std::endl;

    michel.signForm(pardon);
    michel.executeForm(pardon);

    std::cout << "--- ROBOT FORM ---" << std::endl;

    michel.signForm(robot);
    michel.executeForm(robot);

    std::cout << "" << std::endl;
    std::cout << "----- DEBILUS GRADE 150 WORKING -----" << std::endl;
    std::cout << "" << std::endl;

    std::cout << "--- TREE FORM ---" << std::endl;

    debilus.signForm(tree);
    debilus.executeForm(tree);

    std::cout << "--- PARDON FORM ---" << std::endl;

    debilus.signForm(pardon);
    debilus.executeForm(pardon);

    std::cout << "--- ROBOT FORM ---" << std::endl;

    debilus.signForm(robot);
    debilus.executeForm(robot);

    std::cout << "" << std::endl;
    std::cout << "----- DESTRUCTOR -----" << std::endl;
}
