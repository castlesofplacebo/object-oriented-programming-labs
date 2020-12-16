//
// Created by castl on 15.12.2020.
//

#include "../Entities/Worker.h"

std::string Worker::getHierarchy() {
    std::string result;
    result += "Worker : " + this->getName() + "; id = " + std::to_string(this->getId());
    for (Staff *c : employees) {
        if (c == employees.back()) {
            result += "\n  " + c->getHierarchy();
        } else {
            result += c->getHierarchy() + "\n";
        }
    }
    return result;
    //return "=== Worker : " + this->getName() + "; id = " + std::to_string(this->getId()) + " ===";
}

Worker::Worker(std::string _name) : Staff(std::move(_name)) {}

void Worker::addEmployees(Staff *staff) {
    this->employees.push_back(staff);
    staff->setHead(this->getId());
}

std::list<Staff *> Worker::getEmployees() {
    return this->employees;
}

Worker::~Worker() = default;
