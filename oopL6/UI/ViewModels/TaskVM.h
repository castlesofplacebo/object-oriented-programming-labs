//
// Created by castl on 14.12.2020.
//

#ifndef OOPL6_TASKVM_H
#define OOPL6_TASKVM_H

#include <iostream>
#include "StaffVM.h"
#include "../../BLL/DTO/TaskDTO.h"

class TaskVM {
private:
    unsigned int id = 0;
    std::string name{};
    std::string description{};
public:
    TaskVM(std::string _name, std::string _description);

    ~TaskVM();

    std::string getName();

    std::string getDescription();

    void setId(unsigned int _id);

    unsigned int getId() const;

};

#endif //OOPL6_TASKVM_H