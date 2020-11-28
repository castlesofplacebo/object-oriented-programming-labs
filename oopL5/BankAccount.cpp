//
// Created by castl on 27.11.2020.
//

#include "BankAccount.h"

int id = 1;

BankAccount::BankAccount(Client *client1) {
    this->accountID = id;
    ++id;
    this->client = client1;
}

void BankAccount::cashAccount(double _amount) {}

void BankAccount::refillAccount(double _amount) {}

void BankAccount::transferAccount(double _amount, BankAccount *bankAccount) {}

int BankAccount::getAccountID() const {
    return this->accountID;
}

Client *BankAccount::getClient() {
    return this->client;
}

void BankAccount::setVerificationLimit(double limit) {
    this->verificationLimit = limit;
}

void BankAccount::interestPayment() {}

BankAccount::~BankAccount() = default;
