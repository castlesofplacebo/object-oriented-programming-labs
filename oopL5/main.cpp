#include <iostream>
#include "ClientBuilder.h"
#include "Bank.h"
#include "Client.h"
#include "CreditBankAccount.h"
#include "DebitBankAccount.h"
#include "DepositBankAccount.h"

int main() {
    try {
        auto *clientBuilder = new ClientBuilder("Ivanov", "Ivan");
        clientBuilder->setAddress("Sovetskaya st.");
        clientBuilder->setPassport("11 22 33 44");
        Client *client = clientBuilder->getResult();

        auto *clientBuilder1 = new ClientBuilder("Ivanova", "Anna");
        clientBuilder->setAddress("Sovetskaya st.");
        clientBuilder->setPassport("11 22 33 45");
        Client *client1 = clientBuilder->getResult();

        Bank *bank = new Bank("VTB", 10000);

        /*std::vector<std::pair<double, double>> percentAndAmount;
        percentAndAmount.emplace_back(std::make_pair(50000, 3));
        percentAndAmount.emplace_back(std::make_pair(100000, 3.5));
        percentAndAmount.emplace_back(std::make_pair(INT64_MAX, 4));
        BankAccount *account = new DepositBankAccount(60, 51000, percentAndAmount, client1);*/

        BankAccount *account = new CreditBankAccount(200000,3, client1);

        delete clientBuilder;
        delete client;
        delete bank;
        delete account;
    }
    catch (std::exception &err) {
        std::cout << err.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
