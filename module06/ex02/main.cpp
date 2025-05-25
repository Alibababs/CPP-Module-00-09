#include "Base.hpp"

int main( void )
{
	std::srand(static_cast<unsigned int>(std::time(0))); 
	// For testing bad cast just rand % 4 in Base.cpp

	for (int i = 0; i < 10; i++)
	{
		Base *ptr = generate();
		
		std::cout << "Identification by pointer: ";
		identify(ptr);
		
		std::cout << "Identification by reference: ";
		identify(*ptr);
		
		delete ptr;

		std::cout << "----------------------" << std::endl;
	}

    return 0;
}
