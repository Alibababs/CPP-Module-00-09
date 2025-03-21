#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	ph;
	Contact		co;

	std::string command;
	while (1)
	{
		std::cout << "Enter command (ADD ; SEARCH ; EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			ph.addContact();
		else if (command == "SEARCH")
			co.displayShort(2);
		else if (command == "EXIT")
		{
			std::cout << "Goodbye" << std::endl;
			break ;
		}
	}
	return (0);
}
