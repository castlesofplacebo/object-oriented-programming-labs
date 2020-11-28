//
// Created by castl on 27.11.2020.
//

#ifndef OOPL5_BANKACCOUNT_H
#define OOPL5_BANKACCOUNT_H
#include "Client.h"

enum AccountsType {
    Debit,
    Credit,
    Deposit
};

class BankAccount {
protected:
    int accountID = 0;
    int amount = 0;
    bool isVerified = false;
    AccountsType accountType{};
public:
    BankAccount();

    virtual void cashAccount(int _amount);

    virtual void refillAccount();

    virtual void transferAccount();
};

#endif //OOPL5_BANKACCOUNT_H