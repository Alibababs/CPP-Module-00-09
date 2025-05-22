#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &)
{
    std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
   std::cout << "ScalarConverter copy assignment operator called" << std::endl;
//    if (this != &copy)
//         this->_type = copy._type;
   return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}

void ScalarConverter::convert(std::string literal)
{


}
