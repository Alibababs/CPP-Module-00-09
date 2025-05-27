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
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
