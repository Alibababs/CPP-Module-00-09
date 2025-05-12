#include "Cure.hpp"

Cure::Cure() : _type("cure")
{
    std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &copy)
{
    std::cout << "Cure copy constructor called" << std::endl;
    *this = copy;
}

Cure &Cure::operator=(const Cure &copy)
{
   std::cout << "Cure copy assignment operator called" << std::endl;
   if (this != &copy)
        this->_type = copy._type;
   return *this;
}

Cure::~Cure()
{
    std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(std::string const & type) : _type(type)
{
	std::cout << "Cure type constructor called" << std::endl;
}

// const std::string &Cure::getType() const
// {
// 	return _type;
// }

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

// virtual Cure* clone() const = 0;
