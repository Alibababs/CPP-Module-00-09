#include "PmergeMe.hpp"

int main(int argc, char **argv) 
{
	if (argc < 2)
	{
		std::cerr << "Error: Not enough arguments" << std::endl;
	}

	PmergeMe test;

	test.sortAlgo(argc, argv);

	return 0;
}