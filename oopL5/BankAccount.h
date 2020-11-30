//
// Created by castl on 27.11.2020.
//

#ifndef OOPL5_BANKACCOUNT_H
#define OOPL5_BANKACCOUNT_H

#include "Client.h"
#include <map>

struct date {
    int day;
    int month;
    int year;
};

class BankAccount {
protected:
    int accountID = 0;
    double amount = 0;
    double percent = 0;
    double addPercents = 0;
    double verificationLimit = 0;

    Client *client{};
    date lastPercentTime{};
public:
    explicit BankAccount(Client *client1);

    virtual ~BankAccount();

    void setVerificationLimit(double limit);

    virtual void addAmount(double _amount) = 0;

    virtual void getAmount(double _amount, date _date) = 0;

    void calculatePercent(date _date);

    double showAmount();

    [[nodiscard]] double getVerificationLimit() const;

    int getTransactionID();

    [[nodiscard]] int getAccountID() const;

    Client *getClient();

    time_t convertToTimeT(date _date);
};

#endif //OOPL5_BANKACCOUNT_H