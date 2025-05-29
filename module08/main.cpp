#include "Array.hpp"

int main( void ) 
{
	Array<int> test[10];

	try
	{
		test[11];
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	A REFAIRE
	return 0;
}
