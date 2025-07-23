#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) : std::stack<T>(copy)
{
    std::cout << "MutantStack copy constructor called" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &copy)
{
   std::cout << "MutantStack copy assignment operator called" << std::endl;
	if (this != &copy)
		std::stack<T>::operator=(copy);
   return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "MutantStack destructor called" << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}
