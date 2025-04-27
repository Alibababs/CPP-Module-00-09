#include "cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat constructor called" << std::endl;
    _type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
   std::cout << "Copy assignment operator called" << std::endl;
   if (this != &copy)
        this->_type = copy._type;
   return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Miaou" << std::endl;
}
