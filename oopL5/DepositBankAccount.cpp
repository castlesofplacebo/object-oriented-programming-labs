//
// Created by castl on 28.11.2020.
//

#include "DepositBankAccount.h"
#include <utility>

DepositBankAccount::DepositBankAccount(int _daysToEnd, double _openSum,
                                       const std::vector<std::pair<double, double>>& _percentAndAmount,
                                       Client *client1) : BankAccount(client1) {
    this->daysToEnd = _daysToEnd;
    this->openSum = _openSum;

    for (auto & i : _percentAndAmount) {
        if (this->openSum > i.first)
            continue;
        else {
            this->percent = i.second;
            break;
        }
    }
}

//механизм для того, чтобы уменьшать дату в остатке по депозиту
void DepositBankAccount::cashAccount(double _amount) {
    if (!isEndOfDeposit())
        throw std::invalid_argument("Can not cash until end of deposit account");
    if (_amount <= 0)
        throw std::invalid_argument("Can not cash amount negative number");
    if (_amount > this->amount)
        throw std::invalid_argument("Can not cash amount more than on the account now : "
                                    + std::to_string(this->accountID));

    this->amount = this->amount - _amount;
}

void DepositBankAccount::refillAccount(double _amount) {
    if (_amount <= 0)
        throw std::invalid_argument("Can not refill amount negative number");

    this->amount = this->amount + _amount;
}

void DepositBankAccount::transferAccount(double _amount, BankAccount *bankAccount) {
    if (!isEndOfDeposit())
        throw std::invalid_argument("Can not cash until end of deposit account");

    this->cashAccount(_amount);
    bankAccount->refillAccount(_amount);
}

void DepositBankAccount::interestPayment() {
    //запускается каждый день - результат берется каждый месяц
    // => обнуление sumToPay, обновление this->amount
    double currentPercent = this->percent / 365.0;
    this->sumToPay = this->sumToPay + currentPercent * this->amount;
}

bool DepositBankAccount::isEndOfDeposit() const {
    if (daysToEnd == 0)
        return true;
    else return false;
}
