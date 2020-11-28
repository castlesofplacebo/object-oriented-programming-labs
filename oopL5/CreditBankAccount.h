//
// Created by castl on 28.11.2020.
//

#ifndef OOPL5_CREDITBANKACCOUNT_H
#define OOPL5_CREDITBANKACCOUNT_H
#include "BankAccount.h"

class CreditBankAccount : public BankAccount {
private:
    double limit = 0;
    double percent = 0;
    double commission = 0;
public:
    explicit CreditBankAccount(double _limit, double _percent, Client *client1);

    void cashAccount(double _amount) override;

    bool isOutOfLimit();

    void refillAccount(double _amount) override;

    void transferAccount(double _amount, BankAccount *bankAccount) override;

    void interestPayment() override;
};
#endif //OOPL5_CREDITBANKACCOUNT_H