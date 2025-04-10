#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (int intValue)
{
    std::cout << "Int constructor called" << std::endl;
    _value = intValue << _fractionalBits;
}

Fixed::Fixed(float floatValue)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_value = copy.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed &copy) const
{
	std::cout << "Addition operator called" << std::endl;
	Fixed result;
	result.setRawBits(_value + copy.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &copy) const
{
	std::cout << "Soustraction operator called" << std::endl;
	Fixed result;
	result.setRawBits(_value - copy.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &copy) const
{
	std::cout << "Soustraction operator called" << std::endl;
	Fixed result;
	result.setRawBits(_value * copy.getRawBits());
	return (result);
}

Fixed Fixed::operator/(const Fixed &copy) const
{
	std::cout << "Division operator called" << std::endl;
	Fixed result;
	result.setRawBits(_value / copy.getRawBits());
	return (result);
}

int Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int Fixed::toInt(void) const
{
	return (_value >> _fractionalBits);
}

float Fixed::toFloat(void) const
{
	return (float)_value / (1 << _fractionalBits);
}

std::ostream &operator<<( std::ostream &os, const Fixed &copy)
{
	os << copy.toFloat();
	return (os);
}