//
// Created by castl on 14.12.2020.
//

#include "../ViewModels/TaskVM.h"

#include <utility>

TaskVM::TaskVM(std::string _name, std::string _description) {
    this->name = std::move(_name);
    this->description = std::move(_description);
}

std::string TaskVM::getName() {
    return this->name;
}

std::string TaskVM::getDescription() {
    return this->description;
}

void TaskVM::setId(unsigned int _id) {
    this->id = _id;
}

unsigned int TaskVM::getId() const {
    return this->id;
}
