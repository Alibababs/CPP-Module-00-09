#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _data;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &);
        BitcoinExchange &operator=(const BitcoinExchange &);
        ~BitcoinExchange();

        void init();
        void printValue(std::string filename) const;
};

#endif