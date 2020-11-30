//
// Created by castl on 28.11.2020.
//

#ifndef OOPL5_DEBITBANKACCOUNT_H
#define OOPL5_DEBITBANKACCOUNT_H

#include "BankAccount.h"

class DebitBankAccount : public BankAccount {
public:
    explicit DebitBankAccount(Client *client1, int _percent, date _date);

    void addAmount(double _amount) override;

    void getAmount(double _amount, date _date) override;

};

#endif //OOPL5_DEBITBANKACCOUNT_H