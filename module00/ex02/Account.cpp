#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::makeDeposit( int deposit )
{
	_totalNbDeposits++;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";p_amount:" << _amount;
			  _amount += deposit;
			  _totalAmount += deposit;
	std::cout << ";deposit:" << deposit 
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits 
			  << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount;
			  if (_amount < withdrawal)
			  {
				  std::cout << ";withdrawal:refused" << std::endl;
				  return (false);
			  }
			  else
			  {
				  _totalNbWithdrawals++;
				  _nbWithdrawals++;
				  _amount -= withdrawal;
				  _totalAmount -= withdrawal;
				  std::cout << ";withdrawal:" << withdrawal
							<< ";amount:" << _amount
							<< ";nb_withdrawals:" << _nbWithdrawals
							<< std::endl;
			  }
	return (true);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
			  << ";total:" << getTotalAmount()
			  << ";deposits:" << getNbDeposits()
			  << ";withdrawals:" << getNbWithdrawals()
			  << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits 
			  << ";withdrawals:" << _nbWithdrawals 
			  << std::endl;
}

void	Account::_displayTimestamp( void )
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
