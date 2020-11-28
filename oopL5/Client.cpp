//
// Created by castl on 27.11.2020.
//

#include "Client.h"

#include <utility>

Client::Client(std::string _name, std::string _surname) {
    this->name = std::move(_name);
    this->surname = std::move(_surname);
}

Client::Client(Client *client) {
    this->name = client->name;
    this->surname = client->surname;
}
