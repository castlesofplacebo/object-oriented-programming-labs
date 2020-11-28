//
// Created by castl on 28.11.2020.
//

#ifndef OOPL5_BUILDER_H
#define OOPL5_BUILDER_H
#include <iostream>

class Builder {
public:
    virtual ~Builder() = default;;
    virtual void setAddress(std::string _address) = 0;
    virtual void setPassport(std::string _passport) = 0;
};

#endif //OOPL5_BUILDER_H
