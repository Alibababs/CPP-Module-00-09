#include "Contact.hpp"

Contact::Contact()
{
}

void Contact::setInfo()
{
	std::cout << "First name: ";
	std::getline(std::cin, _first_name);
	std::cout << "Last name: ";
	std::getline(std::cin, _last_name);
	std::cout << "Nickname: ";
	std::getline(std::cin, _nickname);
	std::cout << "Phone number: ";
	std::getline(std::cin, _phone_number);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, _darkest_secret);
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
