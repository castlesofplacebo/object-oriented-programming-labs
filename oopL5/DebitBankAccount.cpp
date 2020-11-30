//
// Created by castl on 28.11.2020.
//

#include "DebitBankAccount.h"
#include <iostream>

DebitBankAccount::DebitBankAccount(Client *client1, int _percent, date _date)
        : BankAccount(client1) {
    this->percent = _percent;
    this->lastPercentTime = _date;
}

void DebitBankAccount::addAmount(double _amount) {
    if (_amount < 0)
        throw std::invalid_argument("Can not cash amount negative number");

    this->amount = this->amount + _amount;
}

void DebitBankAccount::getAmount(double _amount, date _date) {
    if (_amount < 0)
        throw std::invalid_argument("Can not cash amount negative number");

    if (_amount > this->amount)
        throw std::invalid_argument("Can not cash amount more than on the account now : "
                                    + std::to_string(this->getAccountID()));

    this->amount = this->amount - _amount;
}