#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	ph;

	std::string command;
	while (1)
	{
		std::cout << "Enter command (ADD ; SEARCH ; EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			ph.addContact();
		else if (command == "SEARCH")
			ph.searchContact();
		else if (command == "EXIT")
		{
			std::cout << "Goodbye" << std::endl;
			break ;
		}
	}
	return (0);
}
