#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &)
{
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &)
{
   std::cout << "Intern copy assignment operator called" << std::endl;
   return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

const char* Intern::FormNameNotExist::what() const throw()
{
    return "Form name does not exist!";
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string names[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};

    int i = -1;
    while (i < 3 && names[i] != name)
        i++;
    switch (i)
    {
        case 0:
            std::cout << "Intern creates ShrubberyCreationForm." << std::endl;
            return new ShrubberyCreationForm(target);
        case 1:
            std::cout << "Intern creates PresidentialPardonForm." << std::endl;
            return new PresidentialPardonForm(target);
        case 2:
            std::cout << "Intern creates RobotomyRequestForm." << std::endl;
            return new RobotomyRequestForm(target);
        default:
            throw FormNameNotExist();
    }
}
