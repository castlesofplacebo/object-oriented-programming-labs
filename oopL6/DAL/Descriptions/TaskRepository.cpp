//
// Created by castl on 13.12.2020.
//

#include "../TaskRepository.h"

TaskRepository::TaskRepository() = default;

void TaskRepository::create(Task *item) {
    item->setId(this->getAll().size() + 1);
    _tasks[item->getId()] = item;
}

Task *TaskRepository::getItem(unsigned int _id) {
    if (_tasks[_id] != nullptr)
        return _tasks[_id];
    else
        throw std::invalid_argument("Task with this ID does not exists " + std::to_string(_id));
}

//void TaskRepository::update(Task *item) {
    //
//}

std::map<unsigned int, Task *> TaskRepository::getAll() {
    return this->_tasks;
}

TaskRepository::~TaskRepository() {
    for (auto i : this->_tasks)
        delete i.second;
}

//std::map<unsigned int, Task *> TaskRepository::find() {
   // return std::map<unsigned int, Task *>();
//}

