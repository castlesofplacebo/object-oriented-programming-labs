//
// Created by castl on 13.12.2020.
//

#include "../Entities/Report.h"

Report::Report(Staff *_staff) {
    this->staff = _staff;
    this->reportState = Started;
}

void Report::addInfo(const std::string& text) {
    this->info += text;
}

unsigned int Report::getId() {
    return this->id;
}

void Report::setId(unsigned int _id) {
    this->id = _id;
}

std::string Report::getInfo() {
    return this->info;
}

void Report::closeReport() {
    this->reportState = Closed;
}

unsigned int Report::getStaffId() {
    return this->staff->getId();

}

ReportState Report::getState() {
    return this->reportState;
}

Report::~Report() = default;
