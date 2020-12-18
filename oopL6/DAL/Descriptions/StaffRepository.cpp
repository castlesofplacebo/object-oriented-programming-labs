//
// Created by castl on 13.12.2020.
//

#include "../StaffRepository.h"

StaffRepository::StaffRepository() = default;

void StaffRepository::create(Staff *item) {
    item->setId(this->getAll().size() + 1);
    _staff[item->getId()] = item;
}

Staff *StaffRepository::getItem(unsigned int _id) {
    if (_staff[_id] != nullptr)
        return _staff[_id];
    else
        throw std::invalid_argument("Staff with this ID does not exists " + std::to_string(_id));
}


std::map<unsigned int, Staff *> StaffRepository::getAll() {
    return this->_staff;
}

StaffRepository::~StaffRepository() {
    for (auto i : this->_staff)
        delete i.second;
}
