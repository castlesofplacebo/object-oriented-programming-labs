//
// Created by castl on 30.11.2020.
//

#include "RefillCommand.h"

RefillCommand::RefillCommand(BankAccount *bankAccount1, date _date) : AbstractCommand(bankAccount1, _date) {}

void RefillCommand::execute(double _amount) {
    this->bankAccount->calculatePercent(this->commandDate);

    this->save(_amount);
    this->bankAccount->addAmount(_amount);
}

void RefillCommand::undo() {
    this->bankAccount->getAmount(this->backup, this->commandDate);
}
