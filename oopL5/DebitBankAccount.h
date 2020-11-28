//
// Created by castl on 28.11.2020.
//

#ifndef OOPL5_DEBITBANKACCOUNT_H
#define OOPL5_DEBITBANKACCOUNT_H
#include "BankAccount.h"

class DebitBankAccount : public BankAccount {
public:
    explicit DebitBankAccount();
    ~DebitBankAccount();

    void cashAccount(int _amount) override;
    void refillAccount() override;
    void transferAccount() override;
};

#endif //OOPL5_DEBITBANKACCOUNT_H