#include <iostream>
#include <vector>
#include "ClientBuilder.h"
#include "Bank.h"
#include "Client.h"
#include "CreditBankAccount.h"
#include "DebitBankAccount.h"
#include "DepositBankAccount.h"
#include "CashCommand.h"
#include "RefillCommand.h"
#include "TransferCommand.h"

int main() {
    try {
        auto *clientBuilder = new ClientBuilder("Ivanov", "Ivan");
        clientBuilder->setAddress("Sovetskaya st.");
        clientBuilder->setPassport("11 22 33 44");
        Client *client = clientBuilder->getResult();


        clientBuilder = new ClientBuilder("Ivanova", "Mary");
        clientBuilder->setAddress("Sovetskaya st.");
        Client *client1 = clientBuilder->getResult();

        Bank *bank = new Bank("VTB", 10000);

        /*std::vector<std::pair<double, double>> percentAndAmount;
        percentAndAmount.emplace_back(std::make_pair(50000, 3));
        percentAndAmount.emplace_back(std::make_pair(100000, 3.5));
        percentAndAmount.emplace_back(std::make_pair(INT64_MAX, 4));
        BankAccount *account = new DepositBankAccount(60, 51000, percentAndAmount, client1);*/

        date _creationDate{10, 10, 2020};
        BankAccount *account = new DebitBankAccount(client, 2, _creationDate);
        BankAccount *account1 = new DebitBankAccount(client1, 2, _creationDate);
        bank->addMember(account);
        bank->addMember(account1);

        date _currentDate{10, 10, 2020};
        AbstractCommand *command = new RefillCommand(account, _currentDate);
        int transID1 = bank->addTransaction(command, 200);

        date _currentDate1{12, 11, 2020};
        account->calculatePercent(_currentDate1);
        //std::cout << account->showAmount();

        AbstractCommand *command1 = new RefillCommand(account1, _currentDate);
        int transID2 = bank->addTransaction(command1, 100);

        //AbstractCommand *command2 = new TransferCommand(account, account1, _currentDate);
        //int transID3 = bank->addTransaction(command2, 100);

        //bank->undoTransaction(transID3);

        std::cout << account->showAmount() << " " << account1->showAmount() << std::endl;

        delete clientBuilder;
        delete client;
        delete bank;
        delete account;
        delete command;
        delete command1;
        //delete command2;
    }
    catch (std::exception &err) {
        std::cout << err.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
