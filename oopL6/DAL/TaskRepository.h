//
// Created by castl on 13.12.2020.
//

#ifndef OOPL6_TASKREPOSITORY_H
#define OOPL6_TASKREPOSITORY_H

#include "Infrastructure/IRepository.h"
#include "Entities/Task.h"
#include <iostream>
#include <map>

class TaskRepository : public IRepository<Task> {
private:
    std::map<unsigned int, Task *> _tasks{};
public:
    TaskRepository();

    ~TaskRepository();

    void create(Task *item) override;

    Task *getItem(unsigned int _id) override;

    //void update(Task *item) override;

    std::map<unsigned int, Task *> getAll() override;

    //std::map<unsigned int, Task *> find() override;

};


#endif //OOPL6_TASKREPOSITORY_H
