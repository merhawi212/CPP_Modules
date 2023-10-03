/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:14:45 by mkiflema          #+#    #+#             */
/*   Updated: 2023/09/30 18:34:31 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(){
	
}

Account::Account(int initial_deposit) {
    this->_accountIndex = _nbAccounts;
    _nbAccounts++;
    this->_amount = initial_deposit;
    _totalAmount += initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}


void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
    this->_amount += deposit;
    _totalAmount += deposit;
    this->_nbDeposits++;
	_totalNbDeposits++;
    std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}


bool Account::makeWithdrawal(int withdrawal) {
     _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount;
    if (this->_amount < withdrawal) {
		std::cout << ";withdrawal:refused" <<std::endl;
        return false;
    }
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount() const {
    return this->_amount;
}

void Account::displayStatus() const {
 	_displayTimestamp();
    std::cout << " index:" <<this->_accountIndex <<";amount:" <<this->_amount 
        << ";deposits:" <<this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals 
	<< std::endl;
}

int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getTotalAmount() {
    return _totalAmount;
}

int Account::getNbDeposits() {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() 
	<< std::endl;
}

void Account::_displayTimestamp() {
    std::time_t now = std::time(0);
    std::tm* timestamp = std::localtime(&now);

    std::cout << "[" << (timestamp->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (timestamp->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << timestamp->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << timestamp->tm_hour
              << std::setw(2) << std::setfill('0') << timestamp->tm_min
              << std::setw(2) << std::setfill('0') << timestamp->tm_sec
              << "]";
}
