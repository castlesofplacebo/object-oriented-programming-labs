//
// Created by castl on 12.12.2020.
//

#ifndef OOPL6_STAFF_H
#define OOPL6_STAFF_H

#include "../Infrastructure/IEntity.h"
#include <iostream>
#include <list>

class Staff : public IEntity {
protected:
    unsigned int id = 0;
    std::string name{};
    unsigned int headId = 0;
public:
    explicit Staff(std::string _name);

    ~Staff();

    std::string getName();

    void setId(unsigned int _id) override;

    unsigned int getHead() const;

    unsigned int getId() override;

    void setHead(unsigned int _id);

    virtual void addEmployees(Staff *staff) = 0;

    virtual std::list<Staff *> getEmployees() = 0;

    virtual std::string getHierarchy() = 0;
};

#endif //OOPL6_STAFF_H
