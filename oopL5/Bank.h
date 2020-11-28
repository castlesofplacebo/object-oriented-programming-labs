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
    int verificationLimit = 0;
    std::map<BankAccount *, int> members{};
public:
    explicit Bank(std::string _bankName, int _verificationLimit);

    void addMember(BankAccount *bankAccount);

    BankAccount *getAccount(Client* client);
};

#endif //OOPL5_BANK_H
