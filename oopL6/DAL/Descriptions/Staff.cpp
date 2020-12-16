//
// Created by castl on 12.12.2020.
//

#include "../Entities/Staff.h"

#include <utility>

Staff::Staff(std::string _name) {
    this->name = std::move(_name);
}

unsigned int Staff::getId() {
    return this->id;
}

void Staff::setId(unsigned int _id) {
    this->id = _id;
}

std::string Staff::getName() {
    return this->name;
}

void Staff::setHead(unsigned int _id) {
    this->headId = _id;
}

unsigned int Staff::getHead() const {
    return this->headId;
}

Staff::~Staff() = default;