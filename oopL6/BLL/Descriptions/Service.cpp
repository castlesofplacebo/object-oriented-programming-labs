//
// Created by castl on 14.12.2020.
//

#include "../Service.h"

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
    for (auto & change : item) {
        if (change.first.day == _date.day
            && change.first.month == _date.month
            && change.first.year == _date.year) {
            result += change.second;
            result += '\n';
        }
    }
    return result;

}

void Service::addStaff(StaffDTO *staff) {
    auto staffToDAL = new Staff(staff->getName());
    this->staffRepository->create(staffToDAL);
    staff->setId(staffToDAL->getId());
}

void Service::setHead(unsigned int headId, unsigned int employeeId) {
    this->staffRepository->getItem(employeeId)->setHead(headId);
}

std::string Service::getHierarchy() {
    std::string result{};

    std::map<unsigned int, Staff *> allStaff = this->staffRepository->getAll();
    for (auto i : allStaff) {
        result += "Employees of " + i.second->getName() + " : ";
        for (auto j : allStaff) {
            if (i.second->getId() == j.second->getHead())
                result += j.second->getName() + " ";
        }
        result += '\n';
    }
    return result;
}

std::vector<TaskDTO> Service::getTasksByDate(date _date) {
    std::vector<TaskDTO> result {};
    std::map<unsigned int, Task *> allTasks = this->taskRepository->getAll();

    for (auto i : allTasks) {
        for (const auto& j : i.second->getChanges()) {
            if (j.first.day == _date.day
                && j.first.month == _date.month
                && j.first.year == _date.year) {
                TaskDTO current(i.second->getName(), i.second->getDescription());
                result.emplace_back(current);
                break;
            }
        }
    }
    return result;
}

std::vector<TaskDTO> Service::getTasksByStaff(StaffDTO *staff) {
    std::vector<TaskDTO> result {};
    std::map<unsigned int, Task *> allTasks = this->taskRepository->getAll();

    for (auto i : allTasks) {
        if (i.second->getStaffId() == staff->getId()) {
            TaskDTO current(i.second->getName(), i.second->getDescription());
            result.push_back(current);
        }
    }
    return result;
}

std::vector<TaskDTO> Service::getEmployeesTasks(StaffDTO *staff) {
    std::vector<TaskDTO> result {};
    std::map<unsigned int, Task *> allTasks = this->taskRepository->getAll();

    for (auto i : allTasks) {
        auto curStaff = this->staffRepository->getItem(i.second->getStaffId());
        if (curStaff->getHead() == staff->getId()) {
            TaskDTO current(i.second->getName(), i.second->getDescription());
            result.push_back(current);
        }
    }
    return result;
}