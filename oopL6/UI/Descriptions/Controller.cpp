//
// Created by castl on 14.12.2020.
//

#include "../Controller.h"

Controller::Controller(Service *service1) {
    this->service = service1;
}

unsigned int Controller::addTask(TaskVM *taskVm, date _date) {
    auto *taskToDTO = new TaskDTO(taskVm->getName(), taskVm->getDescription());
    this->service->addTask(taskToDTO, _date);
    taskVm->setId(taskToDTO->getId());
    return taskToDTO->getId();
}

TaskVM Controller::findTask(unsigned int _id) {
    return TaskVM(this->service->getTask(_id).getName(),
                  this->service->getTask(_id).getDescription());
}

void Controller::setStaffToTask(TaskVM *taskVm, unsigned int staffId, date _date) {
    this->service->setStaff(taskVm->getId(), staffId, _date);
}

void Controller::changeTaskStatus(TaskVM *taskVm, States state, date _date) {
    this->service->changeTaskState(taskVm->getId(), state, _date);
}

void Controller::addCommentToTask(TaskVM *taskVm, const std::string &comment, date _date) {
    this->service->addCommentToTask(taskVm->getId(), comment, _date);
}

std::string Controller::getCommentsFromTask(TaskVM *taskVm) {
    return this->service->getCommentFromTask(taskVm->getId());
}

std::string Controller::seeChangesInTaskByDate(TaskVM *taskVm, date _date) {
    return this->service->seeChangesInTaskByDate(taskVm->getId(), _date);
}

unsigned int Controller::addStaff(StaffVM *staff) {
    auto *staffToDTO = new StaffDTO(staff->getName());
    this->service->addStaff(staffToDTO);
    staff->setId(staffToDTO->getId());
    return staffToDTO->getId();
}

void Controller::setHeadToStaff(StaffVM *head, StaffVM *employee) {
    this->service->setHead(head->getId(), employee->getId());
}

std::string Controller::getHierarchy() {
    return this->service->getHierarchy();
}

std::vector<TaskVM> Controller::getTasksByDate(date _date) {
    std::vector<TaskDTO> tasks = this->service->getTasksByDate(_date);
    std::vector<TaskVM> result {};

    for (auto i : tasks) {
        TaskVM current(i.getName(), i.getDescription());
        result.emplace_back(current);
    }
    return result;
}

std::vector<TaskVM> Controller::getTasksByStaff(StaffVM *staffVm) {
    auto item = new StaffDTO(staffVm->getName());
    item->setId(staffVm->getId());
    std::vector<TaskDTO> tasks = this->service->getTasksByStaff(item);
    std::vector<TaskVM> result {};

    for (auto i : tasks) {
        TaskVM cur(i.getName(), i.getDescription());
        result.emplace_back(cur);
    }
    return result;
}

std::vector<TaskVM> Controller::getEmployeesTasks(StaffVM *staffVm) {
    auto item = new StaffDTO(staffVm->getName());
    item->setId(staffVm->getId());

    std::vector<TaskDTO> tasks = this->service->getEmployeesTasks(item);
    std::vector<TaskVM> result {};

    for (auto i : tasks) {
        TaskVM cur(i.getName(), i.getDescription());
        result.emplace_back(cur);
    }

    return result;
}

