#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::~Point()
{
}

Point::Point(float const &x, float const &y) : _x(x), _y(y)
{
}

Point::Point(const Point &copy) : _x(copy._x) , _y(copy._y)
{
	*this = copy;
}

Point &Point::operator=(const Point &)
{
    return *this;
}

const Fixed &Point::getX(void) const
{
    return (_x);
}

const Fixed &Point::getY(void) const
{
    return (_y);
}
