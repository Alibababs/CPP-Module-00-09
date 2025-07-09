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
   return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}

static bool isChar(const std::string &str) 
{
	return str.length() == 1 && !isdigit(str[0]) && isprint(str[0]);
}

static bool isInt(const std::string &str) 
{
	char *end;
	long value = std::strtol(str.c_str(), &end, 10);
	return *end == '\0' && value >= INT_MIN && value <= INT_MAX;
}

static bool isFloat(const std::string &str) 
{
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return true;
	char *end;
	std::strtof(str.c_str(), &end);
	return *end == 'f' && *(end + 1) == '\0' && *(end - 1) != '.';
}

static bool isDouble(const std::string &str) 
{
	if (str == "nan" || str == "+inf" || str == "-inf")
		return true;
	char *end;
	std::strtod(str.c_str(), &end);
	return *end == '\0' && *(end - 1) != '.';
}

static void printChar(const double &value)
{
    std::cout << "char: ";
	if (std::isnan(value) || value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(const double &value)
{
	std::cout << "int: ";
	if (std::isnan(value) || value < INT_MIN || value > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(const double &value)
{
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1); // For looks like 42.0f
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << static_cast<float>(value) << "f" << std::endl; 
}

static void printDouble(const double &value)
{
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convert(const std::string &literal) 
{
	double value;

	if (isChar(literal)) 
		value = static_cast<double>(literal[0]);
    else if (isInt(literal)) 
		value = static_cast<double>(std::atoi(literal.c_str()));
    else if (isFloat(literal)) 
		value = static_cast<double>(std::strtof(literal.c_str(), NULL));
    else if (isDouble(literal)) 
		value = std::strtod(literal.c_str(), NULL);
    else 
    {
		std::cout << "Invalid literal" << std::endl;
		return ;
	}

	printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
