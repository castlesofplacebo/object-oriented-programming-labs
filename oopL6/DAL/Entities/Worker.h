//
// Created by castl on 15.12.2020.
//

#ifndef OOPL6_WORKER_H
#define OOPL6_WORKER_H

#include "Staff.h"

class Worker : public Staff {
private:
    std::list<Staff *> employees{};
public:
    Worker(std::string _name);

    ~Worker();

    void addEmployees(Staff *staff) override;

    std::string getHierarchy() override;

    std::list<Staff *> getEmployees() override;
};


#endif //OOPL6_WORKER_H
