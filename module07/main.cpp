#include "whatever.hpp"

int main( void )
{
	double a = 42;
	double b = 24;

	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;

	swap(a, b);
	std::cout << "Swap done" << std::endl;

	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;

	std::cout << "Min : " << min(a, b) << std::endl;
	std::cout << "Max : " << max(a, b) << std::endl;

    return 0;
}
