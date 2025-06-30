#include "easyfind.hpp"

int main( void ) 
{
	std::vector<int> v;
	v.push_back (1);
	v.push_back (20);
	v.push_back (42);
	v.push_back (12);
	v.push_back (42);

	std::vector<int>::const_iterator it = easyfind(v, 1);
	if (it == v.end())
		std::cout << "Value not found" << std::endl;
	else
		std::cout << "Value found" << std::endl;
}
