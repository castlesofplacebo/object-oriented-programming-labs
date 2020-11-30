//
// Created by castl on 29.11.2020.
//

#include "CashCommand.h"

void CashCommand::execute(double _amount) {
    this->bankAccount->calculatePercent(this->commandDate);

    this->save(_amount);
    this->bankAccount->getAmount(_amount, this->commandDate);
}

CashCommand::CashCommand(BankAccount *bankAccount1, date _date) : AbstractCommand(bankAccount1, _date) {}

void CashCommand::undo() {
    this->bankAccount->addAmount(this->backup);
}
