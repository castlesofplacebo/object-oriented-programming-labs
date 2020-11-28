//
// Created by castl on 27.11.2020.
//

#ifndef OOPL5_CLIENTDECORATOR_H
#define OOPL5_CLIENTDECORATOR_H

#include "Client.h"

class ClientDecorator : public AbstractClient {
protected:
    AbstractClient *client;
public:
    explicit ClientDecorator(AbstractClient *client1);
};

#endif //OOPL5_CLIENTDECORATOR_H
