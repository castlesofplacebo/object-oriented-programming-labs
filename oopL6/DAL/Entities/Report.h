//
// Created by castl on 13.12.2020.
//

#ifndef OOPL6_REPORT_H
#define OOPL6_REPORT_H

#include "../Infrastructure/IEntity.h"
#include "Staff.h"
#include <iostream>

enum ReportState {
    Started,
    Closed
};

class Report : public IEntity {
private:
    unsigned int id = 0;
    Staff *staff;
    std::string info{};
    ReportState reportState;
public:
    Report(Staff *_staff);

    ~Report();

    void addInfo(const std::string &text);

    void closeReport();

    unsigned int getStaffId();

    ReportState getState();

    std::string getInfo();

    unsigned int getId() override;

    void setId(unsigned int _id) override;
};


#endif //OOPL6_REPORT_H
