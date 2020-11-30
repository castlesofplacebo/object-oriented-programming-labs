//
// Created by castl on 28.11.2020.
//

#include "DepositBankAccount.h"
#include <utility>

DepositBankAccount::DepositBankAccount(int _daysToEnd, double _openSum,
                                       const std::vector<std::pair<double, double>> &_percentAndAmount,
                                       date _date,
                                       Client *client1) : BankAccount(client1) {
    this->daysToEnd = _daysToEnd;
    this->creationDate = _date;
    this->amount = _openSum;

    for (auto &i : _percentAndAmount) {
        if (_openSum > i.first)
            continue;
        else {
            this->percent = i.second;
            break;
        }
    }
    this->lastPercentTime = _date;
}

void DepositBankAccount::addAmount(double _amount) {
    if (_amount < 0)
        throw std::invalid_argument("Can not cash amount negative number");

    this->amount = this->amount + _amount;
}

void DepositBankAccount::getAmount(double _amount, date _date) {
    if (_amount < 0)
        throw std::invalid_argument("Can not cash amount negative number");

    if (this->isEnd(_date))
       throw std::invalid_argument("Can not cash until end of deposit account");

    if ((!this->getClient()->isVerified) && (_amount > this->getVerificationLimit()))
        throw std::invalid_argument("Operation rejected : unverified person");

    this->amount = this->amount - _amount;
}

bool DepositBankAccount::isEnd(date _currentDate) {
    time_t crDate = this->convertToTimeT(creationDate);
    time_t curDate = this->convertToTimeT(_currentDate);

    if (crDate + this->daysToEnd * 3600 * 24 > curDate)
        return true;
    else return false;
}
