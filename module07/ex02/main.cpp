#include "Array.hpp"

int main( void ) 
{
	int * a = new int[10];

	a[9] = 2;

	std::cout << a[9] << std::endl;
	
	return 0;
}
