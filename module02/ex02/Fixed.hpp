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
	Fixed(const Fixed &copy);
	~Fixed();

	Fixed &operator=(const Fixed &copy);
	Fixed operator+(const Fixed &copy) const;
	Fixed operator-(const Fixed &copy) const;
	Fixed operator*(const Fixed &copy) const;
	Fixed operator/(const Fixed &copy) const;
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	bool operator>(const Fixed &copy) const;
	bool operator<(const Fixed &copy) const;
	bool operator>=(const Fixed &copy) const;
	bool operator<=(const Fixed &copy) const;
	bool operator==(const Fixed &copy) const;
	bool operator!=(const Fixed &copy) const;

	static const Fixed &min(const Fixed &copy1, const Fixed &copy2);
	static const Fixed &max(const Fixed &copy1, const Fixed &copy2);

	void setRawBits(int const raw);
	int getRawBits(void) const;
	int toInt( void ) const;
    float toFloat( void ) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &copy);

#endif