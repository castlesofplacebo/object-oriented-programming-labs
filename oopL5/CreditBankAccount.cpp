//
// Created by castl on 28.11.2020.
//

#include "CreditBankAccount.h"
#include <iostream>

CreditBankAccount::CreditBankAccount(double _limit, double _percent, Client *client1) : BankAccount(client1) {
    this->limit = _limit;
    this->percent = _percent;
}

void CreditBankAccount::cashAccount(double _amount) {
    if (_amount <= 0)
        throw std::invalid_argument("Can not cash amount negative number");

    if (!this->isOutOfLimit())
        this->amount = this->amount - _amount;
    else
        throw std::invalid_argument("Out of credit limit");
}

bool CreditBankAccount::isOutOfLimit() {
    if (std::abs(this->amount) <= this->limit)
        return false;
    else return true;
}

void CreditBankAccount::refillAccount(double _amount) {
    if (_amount <= 0)
        throw std::invalid_argument("Can not refill amount negative number");

    this->amount = this->amount + _amount;
}

void CreditBankAccount::transferAccount(double _amount, BankAccount *bankAccount) {
    this->cashAccount(_amount);
    bankAccount->refillAccount(_amount);
}

void CreditBankAccount::interestPayment() {
    //запускается каждый день - результат берется каждый месяц
    // => обнуление this->commission, обновление this->amount
    if (isOutOfLimit()) {
        double currentPercent = this->percent / 365.0;
        this->commission = this->commission + currentPercent * this->amount;
    }
}
