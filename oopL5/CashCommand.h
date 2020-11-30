//
// Created by castl on 29.11.2020.
//

#ifndef OOPL5_CASHCOMMAND_H
#define OOPL5_CASHCOMMAND_H
#include "AbstractCommand.h"

class CashCommand : public AbstractCommand {
public:
    explicit CashCommand(BankAccount *bankAccount1, date _date);
    void execute(double _amount) override;
    void undo() override;
};

#endif //OOPL5_CASHCOMMAND_H
