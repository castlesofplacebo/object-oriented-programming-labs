//
// Created by castl on 28.11.2020.
//

#include "CreditBankAccount.h"
#include <iostream>

CreditBankAccount::CreditBankAccount() : BankAccount() {
    this->accountType = Credit;
}

CreditBankAccount::~CreditBankAccount() = default;