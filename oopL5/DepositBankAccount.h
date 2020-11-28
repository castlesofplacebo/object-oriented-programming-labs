//
// Created by castl on 28.11.2020.
//

#ifndef OOPL5_DEPOSITBANKACCOUNT_H
#define OOPL5_DEPOSITBANKACCOUNT_H

#include "BankAccount.h"
#include <vector>

class DepositBankAccount : public BankAccount {
private:
    int daysToEnd = 0;
    double openSum = 0;
    double percent = 0;
    double sumToPay = 0;
public:
    DepositBankAccount(int _daysToEnd, double _openSum,
                       const std::vector<std::pair<double, double>> &_percentAndAmount, Client *client1);

    [[nodiscard]] bool isEndOfDeposit() const;

    void cashAccount(double _amount) override;

    void refillAccount(double _amount) override;

    void transferAccount(double _amount, BankAccount *bankAccount) override;

    void interestPayment() override;

};

#endif //OOPL5_DEPOSITBANKACCOUNT_H
