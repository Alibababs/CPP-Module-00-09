#include "Contact.hpp"

Contact::Contact()
{
}

void Contact::setInfo()
{
	std::cout << "First name: ";
	while (std::getline(std::cin, _first_name), _first_name.empty())
		std::cout << "Field cannot be empty. Try again: ";
	std::cout << "Last name: ";
	while (std::getline(std::cin, _last_name), _last_name.empty())
		std::cout << "Field cannot be empty. Try again: ";
	std::cout << "Nickname: ";
	while (std::getline(std::cin, _nickname), _nickname.empty())
		std::cout << "Field cannot be empty. Try again: ";
	std::cout << "Phone number: ";
	while (std::getline(std::cin, _phone_number), _phone_number.empty())
		std::cout << "Field cannot be empty. Try again: ";
	std::cout << "Darkest secret: ";
	while (std::getline(std::cin, _darkest_secret), _darkest_secret.empty())
		std::cout << "Field cannot be empty. Try again: ";
}

void Contact::displayShort(int index) const
{
	std::cout << std::setw(10) << index << "|";
	if (_first_name.length() > 10)
		std::cout << std::setw(10) << _first_name.substr(0, 9) + "." << "|";
	else
		std::cout << std::setw(10) << _first_name << "|";
	if (_last_name.length() > 10)
		std::cout << std::setw(10) << _last_name.substr(0, 9) + "." << "|";
	else
		std::cout << std::setw(10) << _last_name << "|";
	if (_nickname.length() > 10)
		std::cout << std::setw(10) << _nickname.substr(0, 9) + "." << std::endl;
	else
		std::cout << std::setw(10) << _nickname << std::endl;
}

void Contact::displayFull() const
{
	std::cout << "First name: " << _first_name << std::endl;
	std::cout << "Last name: " << _last_name << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phone_number << std::endl;
	std::cout << "Darkest secret: " << _darkest_secret << std::endl;
}
