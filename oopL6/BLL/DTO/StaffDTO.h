//
// Created by castl on 13.12.2020.
//

#ifndef OOPL6_STAFFDTO_H
#define OOPL6_STAFFDTO_H
#include <iostream>

class StaffDTO {
protected:
    unsigned int id = 0;
    std::string name{};
    unsigned int headId = 0;
public:
    explicit StaffDTO(std::string _name);

    ~StaffDTO();

    void setId(unsigned int _id);

    std::string getName();

    unsigned int getId() const;
};


#endif //OOPL6_STAFFDTO_H
