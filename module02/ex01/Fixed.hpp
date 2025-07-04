#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
  private:
	int _value;
	const static int _fractionalBits = 8;

  public:
	Fixed();
	Fixed(int intValue);
	Fixed(float floatValue);

	~Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &copy);

	int getRawBits(void) const;
	void setRawBits(int const raw);
    float toFloat(void) const;
	int toInt(void) const;

	
};

std::ostream &operator<<(std::ostream &os, const Fixed &copy);

#endif