//
// Created by castl on 29.11.2020.
//

#include "AbstractCommand.h"

AbstractCommand::AbstractCommand(BankAccount *bankAccount1, date _date) {
    this->bankAccount = bankAccount1;
    this->commandDate = _date;
}

void AbstractCommand::save(double _amount) {
    this->backup = _amount;
}

BankAccount *AbstractCommand::getBankAccount() {
    return this->bankAccount;
}

AbstractCommand::~AbstractCommand() = default;
