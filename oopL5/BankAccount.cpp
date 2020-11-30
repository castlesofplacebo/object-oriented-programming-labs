//
// Created by castl on 27.11.2020.
//

#include "BankAccount.h"
#include <ctime>

int id = 1;
int transactionID = 0;

BankAccount::BankAccount(Client *client1) {
    this->accountID = id;
    ++id;
    this->client = client1;
}

int BankAccount::getAccountID() const {
    return this->accountID;
}

Client *BankAccount::getClient() {
    return this->client;
}

void BankAccount::setVerificationLimit(double limit) {
    this->verificationLimit = limit;
}

int BankAccount::getTransactionID() {
    ++transactionID;
    return transactionID;
}

double BankAccount::getVerificationLimit() const {
    return this->verificationLimit;
}

double BankAccount::showAmount() {
    return this->amount;
}

time_t BankAccount::convertToTimeT (date _date) {
    struct tm t{};
    time_t t_of_day; //date in UNIX-format

    t.tm_year = _date.year - 1900;  // Year - 1900
    t.tm_mon = _date.month - 1;           // Month, where 0 = jan
    t.tm_mday = _date.day;          // Day of the month
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 0;
    t.tm_isdst = -1;        // Is DST on? 1 = yes, 0 = no, -1 = unknown
    t_of_day = mktime(&t);

    return t_of_day;
};

void BankAccount::calculatePercent(date _date) {
    time_t lastDate = this->convertToTimeT(this->lastPercentTime);
    time_t currentDate = this->convertToTimeT(_date);

    double percentPerDay = this->percent / 365;

    if (lastDate + 3600 * 24 * 30 <= currentDate) {
        this->addAmount(percentPerDay * this->amount * _date.day + addPercents);
        this->addPercents = 0;
    }
    else {
        this->addPercents += percentPerDay * this->amount * _date.day;
    }

    this->lastPercentTime = _date;
}

BankAccount::~BankAccount() = default;