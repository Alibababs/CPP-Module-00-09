#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog constructor called" << std::endl;
    _type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    if (copy._brain)
        this->_brain = new Brain(*copy._brain);
    else
        this->_brain = NULL;
}

Dog &Dog::operator=(const Dog &copy)
{
   std::cout << "Dog copy assignment operator called" << std::endl;
   if (this != &copy)
   {
        this->_type = copy._type;
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*copy._brain);
   }
   return *this;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "WOAF" << std::endl;
}

void *Dog::getBrainAddress() const
{
    return (void *)this->_brain;
}

void Dog::setIdea(const int &index, const std::string &idea) 
{
    this->_brain->setIdea(index, idea);
}

const std::string &Dog::getIdea(const int &index) const 
{
    return this->_brain->getIdea(index);
}
