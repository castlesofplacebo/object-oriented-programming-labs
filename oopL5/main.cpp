#include <iostream>
#include "ClientDecorator.h"
#include "ClientAddress.h"
#include "ClientPassport.h"
#include "Bank.h"
#include "Client.h"
#include "CreditBankAccount.h"
#include "DebitBankAccount.h"
#include "AbstractClient.h"

int main() {
    try {
        AbstractClient *client = new Client("Ivan", "Ivanov");
        
        AbstractClient *decorator1 = new ClientAddress("Saint-P", client);

        AbstractClient *decorator2 = new ClientPassport("11 22 33", decorator1);

        Bank *bank = new Bank("VTB");
        bank->addMember(decorator2, new DebitBankAccount());
        //bank->addMember(client, new CreditBankAccount());

        //bank->getAccount(client)->cashAccount(1000);


        delete client;
        delete bank;
    }
    catch (std::exception &err) {
        std::cout << err.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
