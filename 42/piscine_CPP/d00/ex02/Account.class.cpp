/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 18:52:22 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/16 22:34:18 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iomanip>
#include <iostream>

#include "Account.class.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void)
{}

Account::Account(int initial_deposit) : _accountIndex(0), _amount(0),
	_nbDeposits(0), _nbWithdrawals(0)//, _totalCheckAmountCalls(0)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;

	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ';'
		<< "amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{

	Account::_displayTimestamp();
	
	std::cout << " index:" << --_nbAccounts
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
}

int		Account::checkAmount(void) const
{
	//_totalCheckAmountCalls++;
	return _amount;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ';'
		<< "amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t t		= time(0);
	struct tm* now	= localtime(&t);

	std::cout << '[' << (now->tm_year + 1900) << std::setfill ('0') << std::setw (2)
		<< (now->tm_mon + 1)
		<<  now->tm_mday
		<< '_'
		<< now->tm_hour
		<< now->tm_min
		<< now->tm_sec << ']';
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount = _amount;

	_amount += deposit;
	++_nbDeposits;
	_totalAmount += deposit;
	_totalNbDeposits += 1;

	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ';'
		<< "p_amount:" << p_amount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	bool	is_possible = false;
	int		p_amount = _amount;

	if (withdrawal <= _amount) {
		is_possible = true;
		_amount -= withdrawal;
		++_nbWithdrawals;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals += 1;
	}

	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";withdrawal:";
	if (is_possible) {
		std::cout << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	} else {
		std::cout << "refused" << std::endl;
	}
	return is_possible;
}
