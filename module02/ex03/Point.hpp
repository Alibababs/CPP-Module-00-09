#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed _x;
        Fixed _y;
    public:
        Point();
        Point(float a, float b);
        Point(const Point &copy);
        Point &operator=(const Point &copy);
        ~Point();

        const Fixed &getX(void) const;
		const Fixed &getY(void) const;

    };
        
#endif