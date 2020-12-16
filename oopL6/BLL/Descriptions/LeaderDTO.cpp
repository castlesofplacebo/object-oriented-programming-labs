//
// Created by castl on 15.12.2020.
//

#include "../DTO/LeaderDTO.h"

LeaderDTO::LeaderDTO(std::string _name) : StaffDTO(std::move(_name)) {

}

LeaderDTO::~LeaderDTO() = default;
