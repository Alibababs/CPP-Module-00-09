#include "PmergeMe.hpp"

int main(int argc, char **argv) 
{
	if (argc < 2)
	{
		std::cout << "Error: Not enough arguments" << std::endl;
		return (1);
	}

	PmergeMe test;

	if (test.sortAlgo(argc, argv) == 1)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

	return 0;
}