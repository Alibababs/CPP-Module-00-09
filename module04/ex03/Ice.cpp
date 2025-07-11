#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    // std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy._type)
{
    // std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &copy)
{
   std::cout << "Ice copy assignment operator called" << std::endl;
   if (this != &copy)
        this->_type = copy._type;
   return *this;
}

Ice::~Ice()
{
    // std::cout << "Ice destructor called" << std::endl;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}
