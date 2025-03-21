#include <iostream>
#include <ctime>
#include <iomanip>

int main() 
{
    std::time_t now = std::time(0);
    
    std::tm *now_tm = std::localtime(&now);
    
    std::cout << "[" 
			  << (now_tm->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (now_tm->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << now_tm->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << now_tm->tm_hour
              << std::setw(2) << std::setfill('0') << now_tm->tm_min
              << std::setw(2) << std::setfill('0') << now_tm->tm_sec
              << "] ";

    return 0;
}