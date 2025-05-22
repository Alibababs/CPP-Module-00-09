#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "AForm.hpp"

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(std::string target);
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &);
		~ScalarConverter();

        void convert(std::string literal);
};

#endif