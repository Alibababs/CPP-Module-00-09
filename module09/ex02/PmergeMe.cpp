#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    // std::cout << "PmergeMe constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    std::cout << "PmergeMe copy constructor called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
   std::cout << "PmergeMe copy assignment operator called" << std::endl;
   if (this != &copy)
   {
    // _stack = copy._stack;
   }
   return *this;
}

PmergeMe::~PmergeMe()
{
    // std::cout << "PmergeMe destructor called" << std::endl;
}
