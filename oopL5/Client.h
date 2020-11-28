//
// Created by castl on 27.11.2020.
//

#ifndef OOPL5_CLIENT_H
#define OOPL5_CLIENT_H
#include "AbstractClient.h"
#include <iostream>

class Client : public AbstractClient {
private:
    std::string name;
    std::string surname;
public:
    Client(std::string _name, std::string _surname);
    explicit Client(Client *client);
};

#endif //OOPL5_CLIENT_H