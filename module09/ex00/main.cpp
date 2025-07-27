#include "BitcoinExchange.hpp"

int main(int argc, char **argv) 
{
	if (argc != 2)
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return 1;
	}

	BitcoinExchange exchange;

	exchange.initData();

	exchange.printValue(argv[1]);

	return 0;
}