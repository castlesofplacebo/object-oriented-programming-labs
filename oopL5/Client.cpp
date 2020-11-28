//
// Created by castl on 27.11.2020.
//

#include "Client.h"

void Client::verification() {
    if (!this->passport.empty() && !this->address.empty()) {
        this->isVerified = true;
    }
}
