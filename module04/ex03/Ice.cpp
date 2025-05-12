#include "Ice.hpp"

Ice::Ice() : _type("ice")
{
    std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &copy)
{
    std::cout << "Ice copy constructor called" << std::endl;
    *this = copy;
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
    std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(std::string const & type) : _type(type)
{
	std::cout << "Ice type constructor called" << std::endl;
}

// const std::string &Ice::getType() const
// {
// 	return _type;
// }

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

// virtual Ice* clone() const = 0;
