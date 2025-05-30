#include "iter.hpp"

void ft_toupper(char &c)
{
	c = static_cast<char>(std::toupper(static_cast<char>(c)));
}

int main(void)
{
	std::string str = "coucou";

	iter(&str[0], str.length(), ft_toupper);

	std::cout << str << std::endl;

	return 0;
}
