#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0), oldest(0)
{
}

// Ajoute un contact (remplace l'ancien si besoin)
void PhoneBook::addContact()
{
	if (count < 8)
	{
		contacts[count].setInfo();
		count++;
	}
	else
	{
		contacts[oldest].setInfo();
		oldest = (oldest + 1) % 8;
	}
	std::cout << "Contact added successfully!" << std::endl;
}
