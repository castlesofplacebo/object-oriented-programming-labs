//
// Created by castl on 15.12.2020.
//

#ifndef OOPL6_WORKER_H
#define OOPL6_WORKER_H
#include "Staff.h"

class Worker : public Staff {
public:
    std::string getHierarchy() override;
};


#endif //OOPL6_WORKER_H
