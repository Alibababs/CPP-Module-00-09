#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    // std::cout << "BitcoinExchange constructor called" << std::endl;
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
    // std::cout << "BitcoinExchange destructor called" << std::endl;
}

void BitcoinExchange::initData()
{
    std::ifstream file("data.csv");
    std::string line, date;
    float value;

    if (!file.is_open())
    {
        std::cout << "Error: Cannot open file" << std::endl;
        exit (1);
    }

    std::getline(file, line);
    while (getline(file, line)) 
    {
		date = line.substr(0, line.find(","));
        value = static_cast<float>(std::atof(line.substr(line.find(",") + 1).c_str()));
        _data.insert(std::pair<std::string, float>(date, value));
    }
    file.close();
}

static bool isValidDate(const std::string &date, const std::string &line)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }

    for (size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            return false;
        }
    }

    int y = atoi(date.substr(0, 4).c_str());
    int m = atoi(date.substr(5, 2).c_str());
    int d = atoi(date.substr(8, 2).c_str());
    if (m < 1 || m > 12 || d < 1 || d > 31)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }

    return true;
}

static bool isValidValue(const float &value, const std::string &line)
{
    if (value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }

    std::string vl = line.substr(line.find("|") + 2);
    bool hasDot = false;

    for (size_t i = 0; i < vl.length(); i++)
    {
        if (vl[i] == '.')
        {
            if (hasDot || i == 0 || i == vl.length() - 1)
            {
                std::cout << "Error: bad input => " << line << std::endl;
                return false;
            }
            hasDot = true;
        }
        else if (!std::isdigit(vl[i]))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            return false;
        }
    }
    return true;
}

void BitcoinExchange::printValue(std::string filename) const
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: Cannot open file" << std::endl;
        exit (1);
    }

    std::string line;
    getline(file, line);
    if (line != "date | value")
    {
        std::cout << "Error: file must start with: date | value" << std::endl;
        exit (1);
    }

    std::string date;
    size_t bar;
    float value;

    while (getline(file, line))
    {
        bar = line.find('|');
        if (bar == std::string::npos 
            || bar == 0 || bar + 1 >= line.size() 
            || !std::isspace(line[bar - 1]) || !std::isspace(line[bar + 1]))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        date = line.substr(0, bar - 1);
        value = static_cast<float>(std::atof(line.substr(bar + 2).c_str()));
        if (!isValidDate(date, line) || !isValidValue(value, line))
            continue;

        std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
        if (it == _data.end() || it->first != date) 
        {
            if (it == _data.begin()) 
            {
                std::cout << "Error: nothing available for that date => " << date << std::endl;
                continue;
            }
            --it;
        }
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
    }
    file.close();
}
