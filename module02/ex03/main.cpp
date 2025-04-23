#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(void)
{
        Point a(0.0f, 0.0f);
        Point b(5.0f, 0.0f);
        Point c(2.5f, 5.0f);

        Point p(2.5f, 2.0f);

        if (bsp(a, b, c, p))
                std::cout << "Interieur" << std::endl;
        else
                std::cout << "Exterieur" << std::endl;

    return (0);
}
