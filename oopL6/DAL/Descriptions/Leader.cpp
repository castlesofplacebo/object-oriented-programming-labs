//
// Created by castl on 15.12.2020.
//

#include "../Entities/Leader.h"

Leader::Leader(std::string _name) : Staff(_name) {
    this->name = std::move(_name);
}

void Leader::addEmployees(Staff *staff) {
    this->employees.push_back(staff);
    staff->setHead(this->getId());
}

std::string Leader::getHierarchy() {
    std::string result;
    result += "Leader : " + this->getName() + "; id = " + std::to_string(this->getId());
    for (Staff *c : employees) {
        if (c == employees.back()) {
            result += '\n' + c->getHierarchy();
        } else {
            result += '\n' + c->getHierarchy();
        }
    }
    return result;
}

std::list<Staff *> Leader::getEmployees() {
    return this->employees;
}

Leader::~Leader() = default;

