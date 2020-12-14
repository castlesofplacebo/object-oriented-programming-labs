//
// Created by castl on 14.12.2020.
//

#ifndef OOPL6_CONTROLLER_H
#define OOPL6_CONTROLLER_H

#include "../BLL/Service.h"
#include "ViewModels/StaffVM.h"
#include "ViewModels/ReportVM.h"
#include "ViewModels/TaskVM.h"
#include "vector"
#include <iostream>

class Controller {
private:
    Service *service;
public:
    //ok
    Controller(Service *service1);

    //ok
    unsigned int addTask(TaskVM *taskVm, date _date);

    //ok
    TaskVM findTask(unsigned int _id);

    //ok
    void setStaffToTask(TaskVM *taskVm, unsigned int staffId, date _date);

    //ok
    void changeTaskStatus(TaskVM *taskVm, States state, date _date);

    //ok
    void addCommentToTask(TaskVM *taskVm, const std::string &comment, date _date);

    //ok
    std::string getCommentsFromTask(TaskVM *taskVm);

    //ok
    std::string seeChangesInTaskByDate(TaskVM *taskVm, date _date);

    unsigned int addStaff(StaffVM *staff);

    void setHeadToStaff(StaffVM *head, StaffVM *employee);

    std::string getHierarchy();

    std::vector<TaskVM> getTasksByDate(date _date);

    std::vector<TaskVM> getTasksByStaff(StaffVM *staffVm);

    std::vector<TaskVM> getEmployeesTasks(StaffVM *staffVm);
};


#endif //OOPL6_CONTROLLER_H
