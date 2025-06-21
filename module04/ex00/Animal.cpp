#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    _type = copy._type;
}

Animal &Animal::operator=(const Animal &copy)
{
   std::cout << "Animal copy assignment operator called" << std::endl;
   if (this != &copy)
        this->_type = copy._type;
   return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "ANIMALSOUND" << std::endl;
}

std::string Animal::getType() const
{
    return (_type);
}
