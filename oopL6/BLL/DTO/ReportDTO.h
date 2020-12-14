//
// Created by castl on 13.12.2020.
//

#ifndef OOPL6_REPORTDTO_H
#define OOPL6_REPORTDTO_H
#include <iostream>
#include "StaffDTO.h"


class ReportDTO {
private:
    unsigned int id = 0;
    StaffDTO *staff;
    std::string info{};
public:
    ReportDTO(StaffDTO *_staff);

    void addInfo(const std::string &text);

    unsigned int getId();

    void setId(unsigned int _id);
};


#endif //OOPL6_REPORTDTO_H
