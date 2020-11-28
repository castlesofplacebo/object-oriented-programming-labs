//
// Created by castl on 27.11.2020.
//

#ifndef OOPL5_BANKACCOUNT_H
#define OOPL5_BANKACCOUNT_H
#include "Client.h"

class BankAccount {
protected:
    int accountID = 0;
    double amount = 0;
    double verificationLimit = 0;
    Client *client{};
public:
    explicit BankAccount(Client *client1);

    virtual ~BankAccount();

    void setVerificationLimit(double limit);

    virtual void interestPayment() = 0;

    virtual void cashAccount(double _amount) = 0;

    virtual void refillAccount(double _amount) = 0;

    virtual void transferAccount(double _amount, BankAccount *bankAccount) = 0;

    [[nodiscard]] int getAccountID() const;

    Client *getClient();
};

#endif //OOPL5_BANKACCOUNT_H