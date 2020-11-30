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
    date creationDate{};
public:
    DepositBankAccount(int _daysToEnd, double _openSum,
                       const std::vector<std::pair<double, double>> &_percentAndAmount,
                       date _date, Client *client1);

    void addAmount(double _amount) override;

    void getAmount(double _amount, date _date) override;

    bool isEnd(date _date);

};

#endif //OOPL5_DEPOSITBANKACCOUNT_H
