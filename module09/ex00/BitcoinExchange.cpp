#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _data(copy._data)
{
    std::cout << "BitcoinExchange copy constructor called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
   std::cout << "BitcoinExchange copy assignment operator called" << std::endl;
   if (this != &copy)
   {
    _data = copy._data;
   }
   return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "BitcoinExchange destructor called" << std::endl;
}

void BitcoinExchange::init()
{
    std::ifstream file("data.csv");
    std::string line;
    size_t coma;
    float value;
    std::string date;

    while (getline(file, line)) 
    {
        if (line == "date,exchange_rate")
            continue;
        coma = line.find(",");
		date = line.substr (0, coma);
        value = static_cast<float>(std::atof(line.substr(coma + 1).c_str()));
        _data.insert(std::pair<std::string, float>(date, value));
    }
    file.close();
}

// static void handleError(std::string line)
// {

// }

void BitcoinExchange::printValue(std::string filename) const
{
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cout << "Cannot open file" << std::endl;
        return ;
    }

    std::string line;
    while (getline(file, line))
    {
        if (line == "date | value")
            continue;
    }
}