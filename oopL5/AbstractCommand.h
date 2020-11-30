//
// Created by castl on 29.11.2020.
//

#ifndef OOPL5_ABSTRACTCOMMAND_H
#define OOPL5_ABSTRACTCOMMAND_H
#include "BankAccount.h"
#include <map>

class AbstractCommand {
protected:
    double backup = 0.0;
    date commandDate = {};
    BankAccount *bankAccount;
public:
    explicit AbstractCommand(BankAccount *bankAccount1, date _date);

    virtual ~AbstractCommand();

    virtual void execute(double _amount) = 0;

    virtual void undo() = 0;

    void save(double _amount);

    BankAccount* getBankAccount();

};

#endif //OOPL5_ABSTRACTCOMMAND_H
