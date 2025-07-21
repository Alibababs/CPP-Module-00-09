#include "iter.hpp"

void ft_toupper(char &c)
{
	c = static_cast<char>(std::toupper(static_cast<char>(c)));
}

void print_char(const char &c)
{
    std::cout << c;
}

int main(void)
{
	std::string str = "coucou";

	iter(&str[0], str.length(), ft_toupper);
	std::cout << "After ft_toupper: ";
	std::cout << str << std::endl;

	std::cout << "Print characters (const): ";
    iter(&str[0], str.length(), print_char);
    std::cout << std::endl;

	return 0;
}
