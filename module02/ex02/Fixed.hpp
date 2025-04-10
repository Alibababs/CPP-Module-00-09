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
	Fixed operator+(const Fixed &copy) const;
	Fixed operator-(const Fixed &copy) const;
	Fixed operator*(const Fixed &copy) const;
	Fixed operator/(const Fixed &copy) const;
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	int getRawBits(void) const;
	void setRawBits(int const raw);
    float toFloat( void ) const;
	int toInt( void ) const;

	
};

std::ostream &operator<<(std::ostream &os, const Fixed &copy);