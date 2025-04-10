#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0), _oldest(0)
{
}

void PhoneBook::addContact()
{
	if (_count < 8)
	{
		_contacts[_count].setInfo();
		_count++;
	}
	else
	{
		_contacts[_oldest].setInfo();
		_oldest = (_oldest + 1) % 8;
	}
	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContact() const
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < _count; i++)
		_contacts[i].displayShort(i + 1);
	std::cout << "Enter index: ";
	if (std::cin.eof())
		exit (0);
	std::string input;
	std::getline(std::cin, input);
	int index = std::atoi(input.c_str());
	if (index >= 1 && index <= _count)
		_contacts[index - 1].displayFull();
	else
		std::cout << "Invalid index" << std::endl;
}
