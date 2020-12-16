//
// Created by castl on 14.12.2020.
//

#include "../ViewModels/StaffVM.h"

#include <utility>

StaffVM::StaffVM(std::string _name) {
    this->name = std::move(_name);
}

std::string StaffVM::getName() {
    return this->name;
}

void StaffVM::setId(unsigned int _id) {
    this->id = _id;
}

unsigned int StaffVM::getId() const {
    return this->id;
}

StaffVM::~StaffVM() = default;
