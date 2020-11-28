//
// Created by castl on 28.11.2020.
//

#ifndef OOPL5_DEBITBANKACCOUNT_H
#define OOPL5_DEBITBANKACCOUNT_H

#include "BankAccount.h"

class DebitBankAccount : public BankAccount {
private:
    double percent = 0;
    double sumToPay = 0;
public:
    explicit DebitBankAccount(Client *client1, int _percent);

    void cashAccount(double _amount) override;

    void refillAccount(double _amount) override;

    void transferAccount(double _amount, BankAccount *bankAccount) override;

    void interestPayment() override;
};

#endif //OOPL5_DEBITBANKACCOUNT_H