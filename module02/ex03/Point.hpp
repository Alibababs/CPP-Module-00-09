#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point();
        Point(float const &a, float const &b);
        Point(const Point &copy);
        Point &operator=(const Point &);
        ~Point();

        const Fixed &getX(void) const;
		const Fixed &getY(void) const;

    };
        
#endif