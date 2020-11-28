//
// Created by castl on 28.11.2020.
//

#ifndef OOPL5_CLIENTADDRESS_H
#define OOPL5_CLIENTADDRESS_H
#include <iostream>
#include "ClientDecorator.h"

class ClientAddress : public ClientDecorator {
private:
    std::string address;
public:
    ClientAddress(std::string _address, AbstractClient *client1);
};

#endif //OOPL5_CLIENTADDRESS_H
