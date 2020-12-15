//
// Created by castl on 15.12.2020.
//

#include "../Entities/Leader.h"

Leader::Leader(std::string _name) : Staff(_name) {
    this->name = std::move(_name);
}

void Leader::addEmployees(Staff *staff) {
    this->employees.push_back(staff);
    //employee выставить начальника this
    staff->setHead(this->getId());
}

std::string Leader::getHierarchy() {
    std::string result;
    for (Staff *c : employees) {
        if (c == employees.back()) {
            result += c->getHierarchy() + '\n';
        } else {
            result += c->getHierarchy() + "+";
        }
    }
    return result;
}
