#include "AMateria.hpp"

AMateria::AMateria() : _type("notype")
{
    // std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = copy;
}

AMateria &AMateria::operator=(const AMateria &copy)
{
   std::cout << "AMateria copy assignment operator called" << std::endl;
   if (this != &copy)
        this->_type = copy._type;
   return *this;
}

AMateria::~AMateria()
{
    // std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	// std::cout << "AMateria type constructor called" << std::endl;
}

const std::string &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* USE" << target.getName() << " *" << std::endl;
}
