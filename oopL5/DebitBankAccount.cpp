//
// Created by castl on 28.11.2020.
//

#include "DebitBankAccount.h"
#include <iostream>

DebitBankAccount::DebitBankAccount() : BankAccount() {
    this->accountType = Debit;
}

void DebitBankAccount::cashAccount(int _amount) {
    if (_amount <= 0)
        throw std::invalid_argument("Can not cash amount negative number");
    if (_amount > this->amount)
        throw std::invalid_argument("Can not cash amount more than on your account now");
    this->amount = this->amount - _amount;
}

void DebitBankAccount::refillAccount() {
    BankAccount::refillAccount();
}

void DebitBankAccount::transferAccount() {
    BankAccount::transferAccount();
}

DebitBankAccount::~DebitBankAccount() = default;
