#include "iter.hpp"

void ft_toupper(char &c)
{
	c = static_cast<char>(std::toupper(static_cast<char>(c)));
}

template<typename T>
void print_element(const T &c)
{
    std::cout << c;
}

int main(void)
{
	std::string str = "coucou";

	iter(&str[0], str.length(), ft_toupper);
	std::cout << "After ft_toupper: ";
	std::cout << str << std::endl;

	const char *cstr = "hello";

	std::cout << "Print characters (const): ";
    iter(cstr, std::strlen(cstr), print_element<char>);
    std::cout << std::endl;

	int array[] = {1, 2, 3, 4, 5, 42}; 

	std::cout << "Print array: ";
	iter(array, sizeof(array) / sizeof(array[0]), print_element<int>);
    std::cout << std::endl;

	return 0;
}
