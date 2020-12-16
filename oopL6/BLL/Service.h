//
// Created by castl on 14.12.2020.
//

#ifndef OOPL6_SERVICE_H
#define OOPL6_SERVICE_H

#include "../DAL/StaffRepository.h"
#include "../DAL/ReportRepository.h"
#include "../DAL/TaskRepository.h"
#include "../BLL/DTO/TaskDTO.h"
#include "DTO/LeaderDTO.h"
#include "DTO/WorkerDTO.h"

class Service {
private:
    StaffRepository *staffRepository;
    TaskRepository *taskRepository;
    ReportRepository *reportRepository;
public:
    Service(StaffRepository *_staffRepository,
            TaskRepository *_taskRepository,
            ReportRepository *_reportRepository);

    ~Service();

    TaskDTO getTask(unsigned int _id);

    void addTask(TaskDTO *item, date _date);

    void setStaff(unsigned int taskId, unsigned int staffId, date _date);

    void changeTaskState(unsigned int taskId, States state, date _date);

    void addCommentToTask(unsigned int taskId, const std::string &comment, date _date);

    std::string getCommentFromTask(unsigned int taskId);

    std::string seeChangesInTaskByDate(unsigned int taskId, date _date);

    void addTeamleader(LeaderDTO *teamLeadDto);

    void addWorker(WorkerDTO *workerDto);

    void setHead(unsigned int headId, unsigned int employeeId);

    std::string getHierarchy(unsigned int staffId);

    std::vector<TaskDTO> getTasksByDate(date _date);

    std::vector<TaskDTO> getTasksByStaff(unsigned int staffId);

    std::vector<TaskDTO> getEmployeesTasks(unsigned int leaderId);

    void createDailyReport(unsigned int staffId, date _date, const std::string& comment);

    void createSprintReport(WorkerDTO *workerDto, const std::string& comment);

    void createSprintReport(LeaderDTO *leaderDto, const std::string& comment);
};

#endif //OOPL6_SERVICE_H