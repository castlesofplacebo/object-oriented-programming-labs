//
// Created by castl on 13.12.2020.
//

#ifndef OOPL6_IENTITY_H
#define OOPL6_IENTITY_H

class IEntity {
public:
    virtual unsigned int getId() = 0;
    virtual void setId(unsigned int _id) = 0;
};

#endif //OOPL6_IENTITY_H