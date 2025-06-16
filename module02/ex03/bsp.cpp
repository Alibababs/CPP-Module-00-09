#include "Point.hpp"
#include "Fixed.hpp"

float sign(Point const &p1, Point const &p2, Point const &p3)
{
    return (p1.getX().toFloat() - p3.getX().toFloat()) * (p2.getY().toFloat() - p3.getY().toFloat()) -
           (p2.getX().toFloat() - p3.getX().toFloat()) * (p1.getY().toFloat() - p3.getY().toFloat());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float d1 = sign(point, a, b);
    float d2 = sign(point, b, c);
    float d3 = sign(point, c, a);

    if (d1 == 0.0f || d2 == 0.0f || d3 == 0.0f)
        return false;
    if ((d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0))
        return true;
    return false;
}
