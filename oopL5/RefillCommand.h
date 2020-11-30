//
// Created by castl on 30.11.2020.
//

#ifndef OOPL5_REFILLCOMMAND_H
#define OOPL5_REFILLCOMMAND_H
#include "AbstractCommand.h"

class RefillCommand : public AbstractCommand {
public:
    explicit RefillCommand(BankAccount *bankAccount1, date _date);
    void execute(double _amount) override;
    void undo() override;
};

#endif //OOPL5_REFILLCOMMAND_H
