#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat constructor called" << std::endl;
    _type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    if (copy._brain)
        this->_brain = new Brain(*copy._brain);
    else
        this->_brain = NULL;    
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
   std::cout << "Cat copy assignment operator called" << std::endl;
   if (this != &copy)
   {
        this->_type = copy._type;
        if (this->_brain)
            delete this->_brain;
        if (copy._brain)
            this->_brain = new Brain(*copy._brain);
        else
            this->_brain = NULL;
    }
   return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}

void Cat::makeSound() const
{
    std::cout << "MIAOU" << std::endl;
}

void *Cat::getBrainAddress() const
{
    return (void *)this->_brain;
}

void Cat::setIdea(const int &index, const std::string &idea) 
{
    this->_brain->setIdea(index, idea);
}

const std::string &Cat::getIdea(const int &index) const 
{
    return this->_brain->getIdea(index);
}
