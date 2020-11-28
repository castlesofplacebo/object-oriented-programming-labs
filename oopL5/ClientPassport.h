//
// Created by castl on 28.11.2020.
//

#ifndef OOPL5_CLIENTPASSPORT_H
#define OOPL5_CLIENTPASSPORT_H
#include "ClientDecorator.h"

class ClientPassport : public ClientDecorator {
private:
    std::string passport{};
public:
    ClientPassport(std::string _passport, AbstractClient *client1);
};

#endif //OOPL5_CLIENTPASSPORT_H
