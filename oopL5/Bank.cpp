//
// Created by castl on 27.11.2020.
//

#include "Bank.h"
#include "CashCommand.h"
#include "RefillCommand.h"
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

int Bank::addTransaction(AbstractCommand *command, double _amount) {
    if (this->getAccount(command->getBankAccount()->getClient()) == nullptr)
        throw std::invalid_argument("Account of this client does not exist");

    command->execute(_amount);
    int transID = command->getBankAccount()->getTransactionID();

    this->transactions[transID] = command;
    return transID;
}

void Bank::undoTransaction(int transactionID) {
    if (this->transactions.find(transactionID) == this->transactions.end())
        throw std::invalid_argument("Invalid transaction ID");

    this->transactions.find(transactionID)->second->undo();
}