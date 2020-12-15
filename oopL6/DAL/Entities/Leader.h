//
// Created by castl on 15.12.2020.
//

#ifndef OOPL6_LEADER_H
#define OOPL6_LEADER_H

#include "Staff.h"
#include <list>

class Leader : public Staff {
private:
    std::list<Staff *> employees{};
public:
    explicit Leader(std::string _name);

    void addEmployees(Staff *staff) override;

    std::string getHierarchy() override;
};


#endif //OOPL6_LEADER_H
