//
// Created by castl on 30.11.2020.
//

#include "TransferCommand.h"

TransferCommand::TransferCommand(BankAccount *bankAccount1, BankAccount *bankAccount2, date _date)
:AbstractCommand(bankAccount1, _date)
{
    this->toBankAccount = bankAccount2;
}

void TransferCommand::execute(double _amount) {
    this->bankAccount->calculatePercent(this->commandDate);
    this->toBankAccount->calculatePercent(this->commandDate);

    this->save(_amount);
    this->bankAccount->getAmount(_amount, this->commandDate);
    this->toBankAccount->addAmount(_amount);
}

void TransferCommand::undo() {
    this->bankAccount->addAmount(this->backup);
    this->toBankAccount->getAmount(this->backup, this->commandDate);
}
