#include "Span.hpp"

Span::Span() : _N(0)
{
    std::cout << "Span constructor called" << std::endl;
}

Span::Span(unsigned int N) : _N(N)
{
    std::cout << "Span N constructor called" << std::endl;
}

Span::Span(const Span &copy)
{
    std::cout << "Span copy constructor called" << std::endl;
	*this = copy;
}

Span &Span::operator=(const Span &copy)
{
   std::cout << "Span copy assignment operator called" << std::endl;
   if (this != &copy)
        this->_N = copy._N;
   return *this;
}

Span::~Span()
{
    std::cout << "Span destructor called" << std::endl;
}
