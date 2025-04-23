#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::~Point()
{
}

Point::Point(float x, float y) : _x(x), _y(y)
{
}

Point::Point(const Point &copy)
{
	*this = copy;
}

Point &Point::operator=(const Point &copy)
{
    if (this != &copy)
    {
        this->_x = copy._x;
        this->_y = copy._y;
    }
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
