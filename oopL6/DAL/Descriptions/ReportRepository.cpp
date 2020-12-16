//
// Created by castl on 13.12.2020.
//

#include "../ReportRepository.h"

ReportRepository::ReportRepository() = default;

void ReportRepository::create(Report *item) {
    item->setId(this->getAll().size() + 1);
    _reports[item->getId()] = item;
}

Report *ReportRepository::getItem(unsigned int _id) {
    if (_reports[_id] != nullptr)
        return _reports[_id];
    else
        throw std::invalid_argument("Staff with this ID does not exists " + std::to_string(_id));
}


std::map<unsigned int, Report *> ReportRepository::getAll() {
    return this->_reports;
}
