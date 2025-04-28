#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Brain &Brain::operator=(const Brain &copy)
{
   std::cout << "Brain copy assignment operator called" << std::endl;
   if (this != &copy)
   {
	   for (int i = 0; i < 100; i++)
	   	_ideas[i] = copy._ideas[i];
   }
   return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}
void Brain::setIdea(int const &index, std::string const &idea)
{
    if (index >= 0 && index < 100)
        _ideas[index] = idea;
}

std::string const &Brain::getIdea(const int &index) const
{
    if (index >= 0 && index < 100)
        return this->_ideas[index];
    return this->_ideas[0];
}
