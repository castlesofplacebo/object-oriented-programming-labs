//
// Created by castl on 13.12.2020.
//

#ifndef OOPL6_TASKDTO_H
#define OOPL6_TASKDTO_H

#include <iostream>
#include "../../DAL/Entities/Task.h"
#include "../../DAL/TaskRepository.h"
#include "StaffDTO.h"

class TaskDTO {
private:
    unsigned int id = 0;
    std::string name{};
    std::string description{};
    StaffDTO *staff = nullptr;
    States state{};
    std::string staffComments{};
public:
    TaskDTO(std::string _name, std::string _description);

    ~TaskDTO();

    std::string getName();

    std::string getDescription();

    void changeState(States _state);

    void setId(unsigned int _id);

    void addStaffComments(const std::string &_comment);

    void setStaff(StaffDTO *_staff);

    unsigned int getId() const;

};

#endif //OOPL6_TASKDTO_H
