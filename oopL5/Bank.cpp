//
// Created by castl on 27.11.2020.
//

#include "Bank.h"

#include <utility>

Bank::Bank(std::string _bankName) {
    this->bankName = std::move(_bankName);
}

void Bank::addMember(AbstractClient *client, BankAccount *bankAccount) {
    if (this->members.find(client) != this->members.end())
        throw std::invalid_argument("Account already exists");
    this->members[client] = bankAccount;

}

BankAccount *Bank::getAccount(AbstractClient *client) {
    if (this->members.find(client) == this->members.end())
        throw std::invalid_argument("Account does not exist");
    else
        return this->members.find(client)->second;
}
