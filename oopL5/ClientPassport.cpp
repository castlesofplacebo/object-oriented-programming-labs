//
// Created by castl on 28.11.2020.
//

#include "ClientPassport.h"

#include <utility>

ClientPassport::ClientPassport(std::string _passport, AbstractClient *client1) : ClientDecorator(client1){
    this->passport = std::move(_passport);
}
