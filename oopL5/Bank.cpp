//
// Created by castl on 27.11.2020.
//

#include "Bank.h"
#include <utility>

Bank::Bank(std::string _bankName, int _verificationLimit) {
    this->bankName = std::move(_bankName);
    this->verificationLimit = _verificationLimit;
}

void Bank::addMember(BankAccount *bankAccount) {
    bankAccount->setVerificationLimit(this->verificationLimit);
    for (auto i : this->members)
        if (i.first->getClient() == bankAccount->getClient())
            throw std::invalid_argument("Account of this client already exists");
    this->members[bankAccount] = bankAccount->getAccountID();
}

BankAccount *Bank::getAccount(Client *client) {
    for (auto i : this->members)
        if (i.first->getClient() == client)
            return i.first;
    return nullptr;
}
