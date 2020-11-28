//
// Created by castl on 28.11.2020.
//

#include "ClientAddress.h"

#include <utility>

ClientAddress::ClientAddress(std::string _address, AbstractClient *client1) : ClientDecorator(client1) {
    this->address = std::move(_address);
}
