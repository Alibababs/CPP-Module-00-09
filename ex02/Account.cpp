#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

static int	_nbAccounts = 0;
static int	_totalAmount = 0;
static int	_totalNbDeposits = 0;
static int	_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
}

Account::~Account()
{
}

static int	getNbAccounts( void )
{
	return (_nbAccounts)
}

static int	getTotalAmount( void )
{
	return (_totalAmount);
}

static int	getNbDeposits( void )
{
	return (_totalNbDeposits);
}

static int	getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

static void	displayAccountsInfos( void )
{
}

void	makeDeposit( int deposit )
{
}

bool	makeWithdrawal( int withdrawal )
{
	return false;
}

int		checkAmount( void ) const
{
	return 0;
}

void	displayStatus( void ) const
{
}

static void	_displayTimestamp( void )
{
    std::time_t time = std::time(0);
    
    std::tm *time_tm = std::localtime(&time);
    
    std::cout << "[" 
			  << (time_tm->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (time_tm->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << time_tm->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << time_tm->tm_hour
              << std::setw(2) << std::setfill('0') << time_tm->tm_min
              << std::setw(2) << std::setfill('0') << time_tm->tm_sec
              << "] ";
}