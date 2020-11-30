//
// Created by castl on 28.11.2020.
//

#include "CreditBankAccount.h"
#include <iostream>

CreditBankAccount::CreditBankAccount(double _limit, double _percent,
                                     date _date,
                                     Client *client1) : BankAccount(client1) {
    this->creditLimit = _limit;
    this->percent = _percent;
    this->lastPercentTime = _date;
}

void CreditBankAccount::addAmount(double _amount) {
    if (std::abs(this->amount + _amount) > this->creditLimit)
        throw std::invalid_argument("Out of credit limit");

    if (_amount < 0)
        throw std::invalid_argument("Can not add amount negative number");

    this->amount = this->amount + _amount;
}

void CreditBankAccount::getAmount(double _amount, date _date) {
    if (std::abs(this->amount - _amount) > this->creditLimit)
        throw std::invalid_argument("Out of credit limit");

    if (_amount < 0)
        throw std::invalid_argument("Can not get amount negative number");

    if ((!this->getClient()->isVerified) && (_amount > this->getVerificationLimit()))
        throw std::invalid_argument("Operation rejected : unverified person");

    this->amount = this->amount - _amount;
}