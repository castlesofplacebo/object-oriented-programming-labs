//
// Created by castl on 28.11.2020.
//

#include "DebitBankAccount.h"
#include <iostream>

DebitBankAccount::DebitBankAccount(Client *client1, int _percent) : BankAccount(client1) {
    this->percent = _percent;
}

void DebitBankAccount::cashAccount(double _amount) {
    if (_amount <= 0)
        throw std::invalid_argument("Can not cash amount negative number");
    if (_amount > this->amount)
        throw std::invalid_argument("Can not cash amount more than on the account now : "
                                    + std::to_string(this->accountID));
    if ((!this->client->isVerified) && (_amount > this->verificationLimit))
        throw std::invalid_argument("Operation rejected : unverified person");

    this->amount = this->amount - _amount;
}

void DebitBankAccount::refillAccount(double _amount) {
    if (_amount <= 0)
        throw std::invalid_argument("Can not refill amount negative number");

    this->amount = this->amount + _amount;
}

void DebitBankAccount::transferAccount(double _amount, BankAccount *bankAccount) {
    this->cashAccount(_amount);
    bankAccount->refillAccount(_amount);
}

void DebitBankAccount::interestPayment() { //запускается каждый день - результат берется каждый месяц
    // => обнуление sumToPay, обновление this->amount
    double currentPercent = this->percent / 365.0;
    this->sumToPay = this->sumToPay + currentPercent * this->amount;
}