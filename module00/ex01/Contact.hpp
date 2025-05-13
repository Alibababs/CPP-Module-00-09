#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>

class Contact
{
  private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
	void getCin(const std::string& prompt, std::string& field);
  public:
	Contact();

	void setInfo();
	void displayFull() const;
	void displayShort(int index) const;
};

#endif
