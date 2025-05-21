#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
   std::cout << "Intern copy assignment operator called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm* makeForm(std::string name, std::string target)
{
    std::cout << "COUCOU" << std::endl;
}
