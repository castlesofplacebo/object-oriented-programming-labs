//
// Created by castl on 28.11.2020.
//

#include "ClientBuilder.h"

#include <utility>

ClientBuilder::ClientBuilder(std::string _surname, std::string _name) {
    this->reset();
    this->client->surname = std::move(_surname);
    this->client->name = std::move(_name);
}

ClientBuilder::~ClientBuilder() {
        delete client;
}

void ClientBuilder::setAddress(std::string _address) {
    this->client->address = _address;
    this->client->verification();
}

void ClientBuilder::setPassport(std::string _passport) {
    this->client->passport = _passport;
    this->client->verification();
}

Client *ClientBuilder::getResult() {
    Client* result= this->client;
    this->reset();
    return result;
}

void ClientBuilder::reset() {
    this->client = new Client();
}