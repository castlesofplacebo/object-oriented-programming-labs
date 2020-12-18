//
// Created by castl on 13.12.2020.
//

#ifndef OOPL6_STAFFREPOSITORY_H
#define OOPL6_STAFFREPOSITORY_H
#include "Infrastructure/IRepository.h"
#include "Entities/Staff.h"


class StaffRepository : public IRepository<Staff> {
private:
    std::map<unsigned int, Staff *> _staff{};
public:
    StaffRepository();

    ~StaffRepository();

    void create(Staff *item) override;

    Staff *getItem(unsigned int _id) override;

    //void update(Staff *item) override;

    std::map<unsigned int, Staff *> getAll() override;

    //std::map<unsigned int, Staff *> find() override;

};


#endif //OOPL6_STAFFREPOSITORY_H
