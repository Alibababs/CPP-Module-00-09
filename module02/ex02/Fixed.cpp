#include "Fixed.hpp"

Fixed::Fixed() : _value(0) 
{
}

Fixed::Fixed (int intValue)
{
    _value = intValue << _fractionalBits;
}

Fixed::Fixed(float floatValue)
{
    _value = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
		this->_value = copy.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed &copy) const
{
	Fixed result(this->toFloat() + copy.toFloat());
	return (result);
}

Fixed Fixed::operator-(const Fixed &copy) const
{
	Fixed result(this->toFloat() - copy.toFloat());
	return (result);
}

Fixed Fixed::operator*(const Fixed &copy) const
{
	Fixed result(this->toFloat() * copy.toFloat());
	return (result);
}

Fixed Fixed::operator/(const Fixed &copy) const
{
	Fixed result(this->toFloat() / copy.toFloat());
	return (result);
}

Fixed &Fixed::operator++()
{
	_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(_value);
	return (temp);
}

Fixed &Fixed::operator--()
{
	_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return (temp);
}

const Fixed &Fixed::min(const Fixed &copy1, const Fixed &copy2)
{
	return (copy1.getRawBits() < copy2.getRawBits() ? copy1 : copy2);
}

const Fixed &Fixed::max(const Fixed &copy1, const Fixed &copy2)
{
	return (copy1.getRawBits() > copy2.getRawBits() ? copy1 : copy2);
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