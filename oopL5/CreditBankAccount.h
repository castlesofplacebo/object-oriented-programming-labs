//
// Created by castl on 28.11.2020.
//

#ifndef OOPL5_CREDITBANKACCOUNT_H
#define OOPL5_CREDITBANKACCOUNT_H

#include "BankAccount.h"

class CreditBankAccount : public BankAccount {
private:
    double creditLimit = 0;
public:
    explicit CreditBankAccount(double _limit, double _percent, date _date, Client *client1);

    void addAmount(double _amount) override;

    void getAmount(double _amount, date _date) override;
};

#endif //OOPL5_CREDITBANKACCOUNT_H