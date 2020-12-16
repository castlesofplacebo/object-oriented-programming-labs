//
// Created by castl on 14.12.2020.
//

#include "../Service.h"
#include "../../DAL/Entities/Leader.h"
#include "../../DAL/Entities/Worker.h"
#include "algorithm"

Service::Service(StaffRepository *_staffRepository, TaskRepository *_taskRepository,
                 ReportRepository *_reportRepository) {
    this->staffRepository = _staffRepository;
    this->taskRepository = _taskRepository;
    this->reportRepository = _reportRepository;
}

TaskDTO Service::getTask(unsigned int _id) {
    return TaskDTO(this->taskRepository->getItem(_id)->getName(),
                   this->taskRepository->getItem(_id)->getDescription());
}

void Service::addTask(TaskDTO *item, date _date) {
    auto taskToDAL = new Task(item->getName(), item->getDescription(), _date);
    this->taskRepository->create(taskToDAL);
    item->setId(taskToDAL->getId());
}

void Service::setStaff(unsigned int taskId, unsigned int staffId, date _date) {
    this->taskRepository->getItem(taskId)->setStaff(staffId, _date);
}

void Service::changeTaskState(unsigned int taskId, States state, date _date) {
    this->taskRepository->getItem(taskId)->changeState(state, _date);
}

void Service::addCommentToTask(unsigned int taskId, const std::string &comment, date _date) {
    this->taskRepository->getItem(taskId)->addStaffComments(comment, _date);
}

std::string Service::getCommentFromTask(unsigned int taskId) {
    return this->taskRepository->getItem(taskId)->getComment();
}

std::string Service::seeChangesInTaskByDate(unsigned int taskId, date _date) {
    auto item = this->taskRepository->getItem(taskId)->getChanges();

    std::string result{};
    for (auto &change : item) {
        if (change.first.day == _date.day
            && change.first.month == _date.month
            && change.first.year == _date.year) {
            result += change.second;
            result += '\n';
        }
    }
    return result;

}

void Service::addTeamleader(LeaderDTO *teamLeadDto) {
    auto teamleaderToDAL = new Leader(teamLeadDto->getName());
    this->staffRepository->create(teamleaderToDAL);
    teamLeadDto->setId(teamleaderToDAL->getId());
}


void Service::addWorker(WorkerDTO *workerDto) {
    auto workerToDAL = new Worker(workerDto->getName());
    this->staffRepository->create(workerToDAL);
    workerDto->setId(workerToDAL->getId());
}


void Service::setHead(unsigned int headId, unsigned int employeeId) {
    this->staffRepository->getItem(headId)->
            addEmployees(this->staffRepository->getItem(employeeId));
}

std::string Service::getHierarchy(unsigned int staffId) {
    std::string result = this->staffRepository->getItem(staffId)->getHierarchy();
    return result;
}

std::vector<TaskDTO> Service::getTasksByDate(date _date) {
    std::vector<TaskDTO> result{};
    std::map<unsigned int, Task *> allTasks = this->taskRepository->getAll();

    for (auto i : allTasks) {
        for (const auto &j : i.second->getChanges()) {
            if (j.first.day == _date.day
                && j.first.month == _date.month
                && j.first.year == _date.year) {
                TaskDTO current(i.second->getName(), i.second->getDescription());
                current.setId(i.second->getId());
                result.emplace_back(current);
                break;
            }
        }
    }
    return result;
}

Service::~Service() {
    delete taskRepository;
    delete reportRepository;
    delete staffRepository;
}

std::vector<TaskDTO> Service::getTasksByStaff(unsigned int staffId) {
    std::vector<TaskDTO> result{};
    std::map<unsigned int, Task *> allTasks = this->taskRepository->getAll();

    for (auto i : allTasks) {
        if (i.second->getStaff() == staffId) {
            TaskDTO current(i.second->getName(), i.second->getDescription());
            current.setId(i.second->getId());
            result.push_back(current);
        }
    }
    return result;
}

std::vector<TaskDTO> Service::getEmployeesTasks(unsigned int leaderId) {
    std::vector<TaskDTO> result{};
    std::map<unsigned int, Task *> allTasks = this->taskRepository->getAll();

    std::string hierarchy = this->getHierarchy(leaderId);
    std::vector<unsigned int> employeesId{};
    for (int k = 0; k < hierarchy.size() - 1; ++k) {
        if (hierarchy[k + 1] == '\n')
            employeesId.push_back(hierarchy[k] - '0');
    }
    employeesId.push_back(hierarchy[hierarchy.size() - 1] - '0');
    employeesId.erase(employeesId.begin());

    std::vector<unsigned int>::iterator it;
    for (auto i : allTasks) {
        auto curStaffId = this->staffRepository->getItem(i.second->getId())->getId();
        it = std::find(employeesId.begin(), employeesId.end(), curStaffId);

        if (it != employeesId.end()) {
            TaskDTO current(i.second->getName(), i.second->getDescription());
            current.setId(i.second->getId());
            result.push_back(current);
        }
    }
    return result;
}

void Service::createDailyReport(unsigned int staffId, date _date, const std::string &comment) {
    auto reportToDAL = new Report(this->staffRepository->getItem(staffId));
    this->reportRepository->create(reportToDAL);

    //all changes since last report
    std::vector<TaskDTO> allStaffTasksDTO = this->getTasksByStaff(staffId);
    std::string tasksChanges{};

    for (const auto &i : allStaffTasksDTO) {
        std::vector<std::pair<date, std::string>> changes =
                this->taskRepository->getItem(i.getId())->getChanges();
        for (const auto &j : changes) {
            if (j.first.day == _date.day
                && j.first.month == _date.month
                && j.first.year == _date.year) {
                tasksChanges += j.second + '\n';
            }
        }
    }
    reportToDAL->addInfo("REPORT : " + std::to_string(_date.day) + " "
                         + std::to_string(_date.month) + " " + std::to_string(_date.year) + '\n');
    reportToDAL->addInfo(tasksChanges);
    reportToDAL->addInfo(comment + '\n');//comment to report
}

void Service::createSprintReport(WorkerDTO *workerDto, const std::string& comment) {
    auto reportToDAL = new Report(this->staffRepository->getItem(workerDto->getId()));
    this->reportRepository->create(reportToDAL);

    std::string result{};

    std::map<unsigned int, Report *> _reports = this->reportRepository->getAll();
    for (auto i : _reports) {
        if (i.second->getStaffId() == workerDto->getId()) {
            result += "Report ID : " + std::to_string(i.second->getId()) + '\n';
            result += i.second->getInfo();
            //i.second->closeReport();
        }
    }

    reportToDAL->addInfo("FINAL REPORT : id " + std::to_string(workerDto->getId()) + '\n');
    reportToDAL->addInfo(result);
    reportToDAL->addInfo(comment);
    reportToDAL->closeReport();
}

void Service::createSprintReport(LeaderDTO *leaderDto, const std::string &comment) {
    auto reportToDAL = new Report(this->staffRepository->getItem(leaderDto->getId()));
    this->reportRepository->create(reportToDAL);

    std::string result{};

    std::map<unsigned int, Report *> _reports = this->reportRepository->getAll();
    for (auto i : _reports) {
        if (i.second->getState() == Closed) {
            result += "Report ID : " + std::to_string(i.second->getId()) + '\n';
            result += i.second->getInfo();
        }
    }

    reportToDAL->addInfo("FINAL REPORT BY TEAMLEADER:\n");
    reportToDAL->addInfo(result);
    reportToDAL->addInfo("\nTeamleader comment : " + comment);

    std::cout<<reportToDAL->getInfo();
}
