//
// Created by castl on 15.12.2020.
//

#ifndef OOPL6_WORKERDTO_H
#define OOPL6_WORKERDTO_H
#include "StaffDTO.h"

class WorkerDTO : public StaffDTO {
public:
    explicit WorkerDTO(std::string _name);
};


#endif //OOPL6_WORKERDTO_H
