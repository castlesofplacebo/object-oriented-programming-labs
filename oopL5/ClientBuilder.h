//
// Created by castl on 28.11.2020.
//

#ifndef OOPL5_CLIENTBUILDER_H
#define OOPL5_CLIENTBUILDER_H
#include "Builder.h"
#include "Client.h"

class ClientBuilder : public Builder {
private:
    Client* client {};
public:
    ClientBuilder(std::string _surname, std::string _name);

    void reset();

    ~ClientBuilder() override;

    void setAddress(std::string _address) override;

    void setPassport(std::string _passport) override;

    Client* getResult();
};

#endif //OOPL5_CLIENTBUILDER_H
