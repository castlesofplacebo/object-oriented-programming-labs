//
// Created by castl on 13.12.2020.
//

#include "../Entities/Task.h"

#include <utility>

Task::Task(std::string _name, std::string _description) {
    this->name = std::move(_name);
    this->description = std::move(_description);
    this->state = Open;
}

std::string convertFromStates(States _state) {
    std::string result{};
    if (_state == Open)
        result = "Open";
    else if (_state == Active)
        result = "Active";
    else result = "Resolved";
    return result;
}

void Task::changeState(States _state, date _date) {
    this->state = _state;
    this->changes.emplace_back(_date, "Change state to : " + convertFromStates(_state));
}

void Task::addStaffComments(const std::string &_comment, date _date) {
    this->staffComments += _comment;
    this->changes.emplace_back(_date, "Add comments : " + _comment);
}

void Task::setStaff(unsigned int _id, date _date) {
    if (this->staff == 0) {
        this->staff = _id;
        this->changes.emplace_back(_date, "Set staff with id: " + std::to_string(_id));
    } else
        throw std::invalid_argument("Try to set staff to busy task");
}

unsigned int Task::getId() {
    return this->id;
}

void Task::setId(unsigned int _id) {
    this->id = _id;
}

std::string Task::getName() {
    return this->name;
}

std::string Task::getDescription() {
    return this->description;
}

unsigned int Task::getStaffId() const {
    return this->staff;
}

std::string Task::getComment() {
    return this->staffComments;
}

Task::Task(std::string _name, std::string _description, date _date) {
    this->name = std::move(_name);
    this->description = std::move(_description);
    this->changeState(Open, _date);
}

std::vector<std::pair<date, std::string>> Task::getChanges() {
    return this->changes;
}
