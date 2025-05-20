#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy._type)
{
    std::cout << "Cure copy constructor called" << std::endl;
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

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
    return new Cure();
}
