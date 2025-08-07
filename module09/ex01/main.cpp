#include "RPN.hpp"

int main(int argc, char **argv) 
{
	if (argc != 2)
	{
		std::cout << "Error: Need one argument" << std::endl;
		return (1);
	}

	RPN rpn;

	if (rpn.calculate(argv[1]) == 1)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

	return 0;
}