//
// Created by castl on 30.11.2020.
//

#ifndef OOPL5_TRANSFERCOMMAND_H
#define OOPL5_TRANSFERCOMMAND_H
#include "AbstractCommand.h"

class TransferCommand : public AbstractCommand {
private:
    BankAccount *toBankAccount;
public:
    TransferCommand(BankAccount *bankAccount1, BankAccount *bankAccount2, date _date);
    void execute(double _amount) override;
    void undo() override;
};

#endif //OOPL5_TRANSFERCOMMAND_H
