//
// Created by castl on 13.12.2020.
//

#include "../DTO/TaskDTO.h"

#include <utility>

TaskDTO::TaskDTO(std::string _name, std::string _description) {
    this->name = std::move(_name);
    this->description = std::move(_description);
}

void TaskDTO::changeState(States _state) {
    this->state = _state;
}

void TaskDTO::setId(unsigned int _id) {
    this->id = _id;
}

void TaskDTO::addStaffComments(const std::string &_comment) {
    this->staffComments += _comment;
}

unsigned int TaskDTO::getId() const {
    return this->id;
}

void TaskDTO::setStaff(StaffDTO *_staff) {
    this->staff = _staff;
}

std::string TaskDTO::getName() {
    return this->name;
}

std::string TaskDTO::getDescription() {
    return this->description;
}

TaskDTO::~TaskDTO() = default;
