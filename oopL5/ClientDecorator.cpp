//
// Created by castl on 27.11.2020.
//

#include "ClientDecorator.h"

#include <utility>

ClientDecorator::ClientDecorator(AbstractClient *client1) : client(client1) {}
