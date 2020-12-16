//
// Created by castl on 15.12.2020.
//

#ifndef OOPL6_LEADERDTO_H
#define OOPL6_LEADERDTO_H
#include "StaffDTO.h"


class LeaderDTO : public StaffDTO {
public:
    explicit LeaderDTO(std::string _name);

    ~LeaderDTO();

};


#endif //OOPL6_LEADERDTO_H
