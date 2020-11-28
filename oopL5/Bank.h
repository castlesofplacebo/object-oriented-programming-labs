//
// Created by castl on 27.11.2020.
//

#ifndef OOPL5_BANK_H
#define OOPL5_BANK_H

#include <iostream>
#include <map>
#include "BankAccount.h"
#include "Client.h"

class Bank {
private:
    std::string bankName{};
    std::map<AbstractClient *, BankAccount *> members{};
public:
    explicit Bank(std::string _bankName);

    void addMember(AbstractClient *client, BankAccount *bankAccount);

    BankAccount* getAccount(AbstractClient *client);

};

#endif //OOPL5_BANK_H
