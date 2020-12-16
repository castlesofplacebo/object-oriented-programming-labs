//
// Created by castl on 14.12.2020.
//

#ifndef OOPL6_CONTROLLER_H
#define OOPL6_CONTROLLER_H

#include "../BLL/Service.h"
#include "ViewModels/StaffVM.h"
#include "ViewModels/TaskVM.h"
#include "ViewModels/LeaderVM.h"
#include "ViewModels/WorkerVM.h"
#include "vector"
#include <iostream>

class Controller {
private:
    Service *service;
public:
    Controller(Service *service1);

    unsigned int addTask(TaskVM *taskVm, date _date);

    TaskVM findTask(unsigned int _id);

    void setStaffToTask(TaskVM *taskVm, unsigned int staffId, date _date);

    void changeTaskStatus(TaskVM *taskVm, States state, date _date);

    void addCommentToTask(TaskVM *taskVm, const std::string &comment, date _date);

    std::string getCommentsFromTask(TaskVM *taskVm);

    std::string seeChangesInTaskByDate(TaskVM *taskVm, date _date);
    //ok
    unsigned int addTeamleader(LeaderVM *teamLead);
    //ok
    unsigned int addWorker(StaffVM *workerVm);

    void setHeadToStaff(StaffVM *head, StaffVM *employee);

    std::string getHierarchy(StaffVM *staff);

    std::vector<TaskVM> getTasksByDate(date _date);

    std::vector<TaskVM> getTasksByStaff(StaffVM *staffVm);

    std::vector<TaskVM> getEmployeesTasks(StaffVM *staffVm);

    void createDailyReport(StaffVM *staffVm, date _date, const std::string& comment);

    void createSprintReport(WorkerVM *workerVm, const std::string& comment);

    void createSprintReport(LeaderVM *leaderVm, const std::string &comment);
};


#endif //OOPL6_CONTROLLER_H
