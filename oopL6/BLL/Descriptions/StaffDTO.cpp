//
// Created by castl on 13.12.2020.
//

#include "../DTO/StaffDTO.h"

#include <utility>

StaffDTO::StaffDTO(std::string _name) {
    this->name = std::move(_name);
}

void StaffDTO::setId(unsigned int _id) {
    this->id = _id;
}

unsigned int StaffDTO::getId() const {
    return this->id;
}

std::string StaffDTO::getName() {
    return this->name;
}

StaffDTO::~StaffDTO() = default;
