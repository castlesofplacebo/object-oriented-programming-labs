//
// Created by castl on 28.11.2020.
//

#include "DepositBankAccount.h"

DepositBankAccount::DepositBankAccount() : BankAccount() {
    this->accountType = Deposit;
}

DepositBankAccount::~DepositBankAccount() = default;

