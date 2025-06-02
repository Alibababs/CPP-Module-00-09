#include "RPN.hpp"

RPN::RPN()
{
    // std::cout << "RPN constructor called" << std::endl;
}

RPN::RPN(const RPN &copy)
{
    std::cout << "RPN copy constructor called" << std::endl;
}

RPN &RPN::operator=(const RPN &copy)
{
   std::cout << "RPN copy assignment operator called" << std::endl;
   if (this != &copy)
   {
    // _data = copy._data;
   }
   return *this;
}

RPN::~RPN()
{
    // std::cout << "RPN destructor called" << std::endl;
}
