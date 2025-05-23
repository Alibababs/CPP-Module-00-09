#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cmath>
#include <climits>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(std::string target);
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &);
		~ScalarConverter();
	public:
        static void convert(const std::string &literal);
};

#endif