//
// Created by castl on 27.11.2020.
//

#ifndef OOPL5_CLIENT_H
#define OOPL5_CLIENT_H

#include <iostream>

class Client {
public:
    std::string surname{};
    std::string name{};
    std::string address{};
    std::string passport{};
    bool isVerified = false;

    void verification();
};

#endif //OOPL5_CLIENT_H